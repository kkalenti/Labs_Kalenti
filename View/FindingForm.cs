using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using System.Windows.Forms;

namespace View
{
	/// <summary>
	/// Форма для поиска фигур
	/// </summary>
	public partial class FindingForm : Form
	{
		/// <summary>
		/// Конструктор формы поиска
		/// </summary>
		public FindingForm()
		{
			InitializeComponent();
		}

		/// <summary>
		/// Обработка кнопки поиска подходящих объектов
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SearchButton_Click(object sender, EventArgs e)
		{
			var mainForm = (MainForm)this.Owner;
			FigureGrid.Rows.Clear();
			if (RectangleCheckBox.Checked || CircleCheckBox.Checked)
			{
				foreach (IFigure figure in mainForm.Figures)
				{
					if (figure is Model.Rectangle && RectangleCheckBox.Checked)
					{
						AddToGrid("Rectangle", figure);
					}
					else if (figure is Model.Circle && CircleCheckBox.Checked)
					{
						AddToGrid("Circle", figure);
					}
				}
			}
		}

		/// <summary>
		/// Добавление фигуры в список
		/// </summary>
		/// <param name="name">Название фигуры</param>
		/// <param name="figure">Фигура</param>
		public void AddToGrid(string name, IFigure figure)
		{
			if (IsBetween(Convert.ToDouble(SurfaceFirstTextBox.Text),
				Convert.ToDouble(SurfaceSecondTextBox.Text), figure.Surface) &&
				IsBetween(Convert.ToDouble(PerimeterFirstTextBox.Text),
				Convert.ToDouble(PerimeterSecondTextBox.Text), figure.Perimeter))
			{
				FigureGrid.Rows.Add(name, figure.Surface, figure.Perimeter);
			}
		}

		/// <summary>
		/// Проверка на вхождение в интервал
		/// </summary>
		/// <param name="min">Минимум</param>
		/// <param name="max">Максимум</param>
		/// <param name="argument">Аргумент для проверки</param>
		/// <returns></returns>
		public bool IsBetween(double min, double max, double argument)
		{
			return argument >= min && argument <= max;
		}

		/// <summary>
		/// Валидация для полей площади
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SurfaceFirstTextBox_Validating(object sender, CancelEventArgs e)
		{
			//TODO: Дубль done
			CheckFields(SurfaceFirstTextBox, SurfaceSecondTextBox, sender, e);
		}

		/// <summary>
		/// Валидация для полей периметра
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void PerimeterFirstTextBox_Validating(object sender, CancelEventArgs e)
		{
			//TODO: Дубль done
			CheckFields(PerimeterFirstTextBox, PerimeterSecondTextBox, sender, e);
		}

		/// <summary>
		/// Полная проверка полей периметра
		/// </summary>
		/// <param name="firstField">Первое поле</param>
		/// <param name="secondField">Второе поле</param>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// TODO: Метод говно. Много параметров передаётся и делается одно и тоже
		private void CheckFields(TextBox firstField, TextBox secondField, object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (!BlankFieldChecking(out errorMsg))
			{
				SearchButton.Enabled = false;
				SetError(firstField, secondField, errorMsg, sender, e);
			}
			else
			{
				SearchButton.Enabled = true;
				errorMsg = "";
				SetError(firstField, secondField, errorMsg, sender, e);
			}
		}

		/// <summary>
		/// Запрет на ввод всего проме цифр и backspace
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SurfaceFirstTextBox_KeyPress(object sender, KeyPressEventArgs e)
		{
			//TODO: Инвертируй, будет лучше читаться
			if (!(char.IsDigit(e.KeyChar)))
			{
				if (e.KeyChar != (char)Keys.Back)
				{
					e.Handled = true;
				}
			}
		}

		/// <summary>
		/// Установить ошибки для полей
		/// </summary>
		/// <param name="firstStr">Первое поле</param>
		/// <param name="secondStr">Второе поле</param>
		/// <param name="errorMsg">Сообщение об ошибке</param>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// TODO: Метод плохой, не стоит сюда передавать sender и е
		/// TODO: почему паблик?
		public void SetError(TextBox firstStr, TextBox secondStr,
			string errorMsg, object sender, CancelEventArgs e)
		{
			this.errorProvider.SetError(SurfaceFirstTextBox, errorMsg);
			this.errorProvider.SetError(SurfaceSecondTextBox, errorMsg);
			this.errorProvider.SetError(PerimeterFirstTextBox, errorMsg);
			this.errorProvider.SetError(PerimeterSecondTextBox, errorMsg);
			if (!ValidValueGap(firstStr.Text, secondStr.Text, out errorMsg))
			{
				e.Cancel = true;
				(sender as TextBox).Select(0, (sender as TextBox).Text.Length);
				this.errorProvider.SetError((sender as TextBox), errorMsg);
			}
		}

		/// <summary>
		/// Проверка на пустую строку
		/// </summary>
		/// <param name="errorMessage">Текст ошибки</param>
		/// <returns></returns>
		public bool BlankFieldChecking(out string errorMessage)
		{
			//TODO: Длинные строки
			if (SurfaceFirstTextBox.Text.Length == 0 || SurfaceSecondTextBox.Text.Length == 0 ||
				PerimeterFirstTextBox.Text.Length == 0 || PerimeterSecondTextBox.Text.Length == 0)
			{
				errorMessage = "All fields must be filled in";
				return false;
			}
			errorMessage = "";
			return true;
		}

		/// <summary>
		/// Проверка на соответствие условию
		/// значение первой строки меньше или равно значению второй
		/// </summary>
		/// <param name="firstStr">Первая строка</param>
		/// <param name="secondStr">Вторая строка</param>
		/// <param name="errorMessage">Текст ошибки</param>
		/// <returns></returns>
		public bool ValidValueGap(string firstStr, string secondStr, out string errorMessage)
		{
			if (firstStr.Length != 0 && secondStr.Length != 0)
			{
				//TODO: Потенциальная генерация исключений!
				if (Convert.ToDouble(firstStr) > Convert.ToDouble(secondStr))
				{
					errorMessage = "Second value must be more or equal to the first";
					return false;
				}
			}
			errorMessage = "";
			return true;
		}
	}
}
