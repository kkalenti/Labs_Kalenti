using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace View
{
	/// <summary>
	/// Форма для добавления объектов
	/// </summary>
	public partial class AddingForm : Form
	{
		//TODO: RSDN!
		public AddingForm()
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
			CircleGroupBox.Enabled = true;
			//TODO: Дублирование
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
			CircleGroupBox.Enabled = false;
			//TODO: Дублирование
			RadiusTextBox.Text = "";
			this.errorProvider.SetError(RadiusTextBox, "");
		}

		/// <summary>
		/// Обработка кнопки отмены
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void CancelButton_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		/// <summary>
		/// Обработка кнопки добавления объекта
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void AddButton_Click(object sender, EventArgs e)
		{
			//TODO: фубл... фунах...
			var mainForm = (MainForm)this.Owner;
			if (CircleRadioButton.Checked)
			{
				var radius = Convert.ToDouble(RadiusTextBox.Text);
				mainForm.CircleToList(radius);
			}
			else
			{
				var width = Convert.ToDouble(WidthTextBox.Text);
				var length = Convert.ToDouble(LengthTextBox.Text);
				mainForm.RectangleToList(width, length);
			}
			this.Close();
		}

		/// <summary>
		/// Запрет на ввод любых символов кроме цифр и backspace
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RadiusTextBox_KeyPress(object sender, KeyPressEventArgs e)
		{
			//TODO: Инвертируй, будет лучше читаться
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
			//TODO: Можно вписать в IsZero
			string errorMsg;
			if (IsZero(RadiusTextBox.Text, out errorMsg)){
				AddButton.Enabled = false;
				this.errorProvider.SetError(RadiusTextBox, errorMsg);
			}
			else
			{
				AddButton.Enabled = true;
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
			//TODO: var + resharper
			foreach(char letter in field)
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
			//TODO: Скорее всего можно переписать проще, куча однотипных условий
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
		/// TODO: Метод не оч. я бы передавал текстбокс, строку и енаблед с false по-умолчанию
		public void SetError(bool buttonEnabled, string widthErr, string lengthErr)
		{
			AddButton.Enabled = buttonEnabled;
			this.errorProvider.SetError(WidthTextBox, widthErr);
			this.errorProvider.SetError(LengthTextBox, lengthErr);
		}
	}
}
