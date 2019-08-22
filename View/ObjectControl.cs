using System;
//TODO: using
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
	//TODO: XML
	public partial class ObjectControl : UserControl
	{
		/// <summary>
		/// Свойство для хранения используемой фигуры
		/// </summary>
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
						EnableButton(false);

						WidthTextBox.Text = rectangle.Width.ToString();
						LengthTextBox.Text = rectangle.Length.ToString();
						break;
					}
					case Model.Circle circle:
					{
						EnableButton(false);
						CircleRadioButton.Checked = true;

						RadiusTextBox.Text = circle.Radius.ToString();
						break;
					}
				}
			}
		}

		/// <summary>
		/// Отключает или включает radiobutton-ы
		/// </summary>
		/// <param name="enable"></param>
		private void EnableButton(bool enable)
		{
			RectangleRadioButton.Enabled = enable;
			CircleRadioButton.Enabled = enable;
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
				TextBoxesEnable(!_readOnly);
			}
		}

		/// <summary>
		/// Отключает или включает textbox-ы
		/// </summary>
		/// <param name="enable"></param>
		private void TextBoxesEnable(bool enable)
		{
			WidthTextBox.Enabled = enable;
			LengthTextBox.Enabled = enable;
			RadiusTextBox.Enabled = enable;
		}

		/// <summary>
		/// Очистить все textbox-ы
		/// </summary>
		public void ClearFields()
		{
			WidthTextBox.Text = "";
			LengthTextBox.Text = "";
			RadiusTextBox.Text = "";
		}

		/// <summary>
		/// Разрешение на добавление элемента исходя из валидации
		/// </summary>
		public bool IsAddingEnable { get; private set; }

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
			ClearTextBoxError(WidthTextBox);
			ClearTextBoxError(LengthTextBox);
		}

		/// <summary>
		/// Очищает текст ошибки для textbox-а
		/// </summary>
		/// <param name="textBox"></param>
		private void ClearTextBoxError(Control textBox)
		{
			textBox.Text = "";
			errorProvider.SetError(textBox, "");
		}

		/// <summary>
		/// Отключение доступа и скрытие контрола
		/// </summary>
		/// <param name="groupBox"> Выбранный GroupBox</param>
		/// <param name="enable">Доступ</param>
		private void EnabledGroupBox(GroupBox groupBox, bool enable)
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
			ClearTextBoxError(RadiusTextBox);
		}

		/// <summary>
		/// Запрет на ввод любых символов кроме цифр и backspace
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RadiusTextBox_KeyPress(object sender, KeyPressEventArgs e)
		{
			if (char.IsDigit(e.KeyChar)) return;

			if (e.KeyChar != (char)Keys.Back &&
			    (e.KeyChar != ',' || RadiusTextBox.Text.Contains(',')))
			{
				e.Handled = true;
			}
		}

		/// <summary>
		/// Проверка на валидность введенных данных о круге
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RadiusTextBox_Validating(object sender, CancelEventArgs e)
		{
			//TODO:Можно упростить
			if (string.IsNullOrEmpty(SetError(RadiusTextBox)))
			{
				IsAddingEnable = true;
			}
			else
			{
				IsAddingEnable = false;
			}
		}

		/// <summary>
		/// Проверка стрки на отсутствие символов
		/// </summary>
		/// <param name="field">Введенная строка</param>
		/// <returns>TODO</returns>
		/// TODO: Лучше сделать статическим
		private string EmptyFieldValidation(string field)
		{
			double.TryParse(field, out var doubleValue);
			if (string.IsNullOrEmpty(field) || doubleValue == 0)
			{
				return  "Value mustn't be equal 0 or empty";
			}
			return "";
		}

		/// <summary>
		/// Валидация для полей добавления прямоугольника
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void WidthTextBox_Validating(object sender, CancelEventArgs e)
		{
			//TODO:Можно упростить
			if (string.IsNullOrEmpty(SetError(WidthTextBox)) &&
			    string.IsNullOrEmpty(SetError(LengthTextBox)))
			{
				IsAddingEnable = true;
			}
			else
			{
				IsAddingEnable = false;
			}

		}

		/// <summary>
		/// Возвращает текст ошибки для данного textbox-а
		/// </summary>
		/// <param name="textBox">Проверяемый textbox</param>
		/// <returns>Сообщение ошибки</returns>
		private string SetError(Control textBox)
		{
			var errorMsg = EmptyFieldValidation(textBox.Text);
			this.errorProvider.SetError(textBox, errorMsg);

			return errorMsg;
		}
	}
}
