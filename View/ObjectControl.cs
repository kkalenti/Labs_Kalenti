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
		/// <summary>
		/// Свойство для хранения используемой фигуры
		/// </summary>
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
						RectangleRadioButton.Enabled = false;
						CircleRadioButton.Checked = false;
						CircleRadioButton.Enabled = false;

						WidthTextBox.Text = rectangle.Width.ToString();
						LengthTextBox.Text = rectangle.Length.ToString();
						break;
					}
					case Model.Circle circle:
					{
						RectangleRadioButton.Checked = false;
						RectangleRadioButton.Enabled = false;
						CircleRadioButton.Checked = true;
						CircleRadioButton.Enabled = false;

						RadiusTextBox.Text = circle.Radius.ToString();
						break;
					}
				}
			}
		}

		/// <summary>
		/// Запрет на редактирование информации
		/// </summary>
		private bool _readOnly = true;

		/// <summary>
		/// Свойство запрет на редактирование информации
		/// </summary>
		public bool ReadOnly
		{
			get => _readOnly;
			set
			{
				_readOnly = value;
				WidthTextBox.Enabled = !_readOnly;
				LengthTextBox.Enabled = !_readOnly;
				RadiusTextBox.Enabled = !_readOnly;
			}
		}

		public void CleanFields()
		{
			WidthTextBox.Text = "";
			LengthTextBox.Text = "";
			RadiusTextBox.Text = "";
		}

		/// <summary>
		/// Разрешение на добавление элемента исходя из валидации
		/// </summary>
		public bool AddingEnable { get; private set; }

		/// <summary>
		/// Конструктор контрола
		/// </summary>
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
			EnabledGroupBox(RectangleGroupBox, false);
			EnabledGroupBox(CircleGroupBox, true);
			WidthTextBox.Text = "";
			LengthTextBox.Text = "";
			this.errorProvider.SetError(WidthTextBox, "");
			this.errorProvider.SetError(LengthTextBox, "");
		}

		/// <summary>
		/// Отключение доступа и скрытие контрола
		/// </summary>
		/// <param name="groupBox"> Выбранный GroupBox</param>
		/// <param name="enable">Доступ</param>
		public void EnabledGroupBox(GroupBox groupBox, bool enable)
		{
			groupBox.Enabled = enable;
			groupBox.Visible = enable;
		}

		/// <summary>
		/// Выбор ввода информации о прямоугольниках
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RectangleRadioButton_CheckedChanged(object sender, EventArgs e)
		{
			EnabledGroupBox(RectangleGroupBox, true);
			EnabledGroupBox(CircleGroupBox, false);
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
			if (IsZero(RadiusTextBox.Text, out var errorMsg))
			{
				AddingEnable = false;
				this.errorProvider.SetError(RadiusTextBox, errorMsg);
			}
			else
			{
				AddingEnable = true;
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
			if (IsZero(WidthTextBox.Text, out var widthErrorMsg) 
			    && IsZero(LengthTextBox.Text, out var lengthErrorMsg))
			{
				SetError(false, widthErrorMsg, lengthErrorMsg);
			}
			else if (IsZero(WidthTextBox.Text, out widthErrorMsg) 
			         && !IsZero(LengthTextBox.Text, out lengthErrorMsg))
			{
				SetError(false, widthErrorMsg, "");
			}
			else if (!IsZero(WidthTextBox.Text, out widthErrorMsg)
			         && IsZero(LengthTextBox.Text, out lengthErrorMsg))
			{
				SetError(false, "", lengthErrorMsg);
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
			AddingEnable = buttonEnabled;
			this.errorProvider.SetError(WidthTextBox, widthErr);
			this.errorProvider.SetError(LengthTextBox, lengthErr);
		}
	}
}
