using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Model;
using Model.Interfaces;

namespace View
{
	public partial class ObjectControl : UserControl
	{
		public IFigure Object
		{
			get
			{
				if (RectangleRadioButton.Checked)
				{
					var width = Convert.ToDouble(WidthTextBox.Text);
					var length = Convert.ToDouble(LengthTextBox.Text);
					IFigure rectangle = new Model.Rectangle(width, length);
					return rectangle;
				}
				else
				{
					var radius = Convert.ToDouble(RadiusTextBox.Text);
					IFigure circle = new Model.Circle(radius);
					return circle;
				}
			}
			set
			{
				switch (value)
				{
					case Model.Rectangle rectangle:
					{
						RectangleRadioButton.Checked = true;
						CircleRadioButton.Checked = true;

						WidthTextBox.Text = rectangle.Width.ToString();
						LengthTextBox.Text = rectangle.Length.ToString();
						break;
					}
					case Model.Circle circle:
					{
						RectangleRadioButton.Checked = true;
						CircleRadioButton.Checked = true;

						RadiusTextBox.Text = circle.Radius.ToString();
						break;
					}
				}
			}
		}

		private bool _readOnly = true;

		public bool ReadOnly
		{
			get => _readOnly;
			set
			{
				WidthTextBox.ReadOnly = value;
				LengthTextBox.ReadOnly = value;
				RadiusTextBox.ReadOnly = value;
			}
		}

		public ObjectControl()
		{
			InitializeComponent();
		}

		/// <summary>
		/// Выбор ввода информации о кругах
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void CircleRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			RectangleGroupBox.Enabled = false;
			RectangleGroupBox.Visible = false;
			CircleGroupBox.Enabled = true;
			CircleGroupBox.Visible = true;
			WidthTextBox.Text = "";
			LengthTextBox.Text = "";
			this.errorProvider.SetError(WidthTextBox, "");
			this.errorProvider.SetError(LengthTextBox, "");
		}

		/// <summary>
		/// Выбор ввода информации о прямоугольниках
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RectangleRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			RectangleGroupBox.Enabled = true;
			RectangleGroupBox.Visible = true;
			CircleGroupBox.Enabled = false;
			CircleGroupBox.Visible = false;
			RadiusTextBox.Text = "";
			this.errorProvider.SetError(RadiusTextBox, "");
		}

		/// <summary>
		/// Запрет на ввод любых символов кроме цифр и backspace
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RadiusTextBox_KeyPress(object sender, KeyPressEventArgs e)
		{
			if (!char.IsDigit(e.KeyChar))
			{
				if (e.KeyChar != (char)Keys.Back &&
				    (e.KeyChar != ',' || RadiusTextBox.Text.Contains(',')))
				{
					e.Handled = true;
				}
			}
		}

		/// <summary>
		/// Проверка на валидность введенных данных о круге
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RadiusTextBox_Validating(object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (IsZero(RadiusTextBox.Text, out errorMsg))
			{
				this.errorProvider.SetError(RadiusTextBox, errorMsg);
			}
			else
			{
				errorMsg = "";
				this.errorProvider.SetError(RadiusTextBox, errorMsg);
			}
		}

		/// <summary>
		/// Проверка стрки на отсутствие символов
		/// </summary>
		/// <param name="field">Введенная строка</param>
		/// <param name="errorMessage">Сообщение об ошибке</param>
		/// <returns></returns>
		public bool IsZero(string field, out string errorMessage)
		{
			foreach (char letter in field)
			{
				if (letter != '0')
				{
					errorMessage = "";
					return false;
				}
			}
			errorMessage = "Value mustn't be equal 0 or empty";
			return true;
		}

		/// <summary>
		/// Валидация для полей добавления прямоугольника
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void WidthTextBox_Validating(object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (IsZero(WidthTextBox.Text, out errorMsg) && IsZero(LengthTextBox.Text, out errorMsg))
			{
				SetError(false, errorMsg, errorMsg);
			}
			else if (IsZero(WidthTextBox.Text, out errorMsg) && !IsZero(LengthTextBox.Text, out errorMsg))
			{
				SetError(false, errorMsg, "");
			}
			else if (!IsZero(WidthTextBox.Text, out errorMsg) && IsZero(LengthTextBox.Text, out errorMsg))
			{
				SetError(false, "", errorMsg);
			}
			else
			{
				SetError(true, "", "");
			}
		}

		/// <summary>
		/// Задать текст для ошибки
		/// </summary>
		/// <param name="buttonEnabled">Разрешение на добавление в список</param>
		/// <param name="widthErr">Текст для ошибки поля ширины</param>
		/// <param name="lengthErr">Текст для ошибки поля длины</param>
		public void SetError(bool buttonEnabled, string widthErr, string lengthErr)
		{
			this.errorProvider.SetError(WidthTextBox, widthErr);
			this.errorProvider.SetError(LengthTextBox, lengthErr);
		}
	}
}
