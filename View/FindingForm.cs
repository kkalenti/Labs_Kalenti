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
		/// Ссылка на родительскую форму
		/// </summary>
		static MainForm main;

		public FindingForm()
		{
			InitializeComponent();
		}

		public FindingForm(MainForm mainForm)
		{
			InitializeComponent();
			main = mainForm;
		}

		/// <summary>
		/// Обработка кнопки поиска подходящих объектов
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SearchButton_Click(object sender, EventArgs e)
		{
			FigureGrid.Rows.Clear();
			if (RectangleCheckBox.Checked || CircleCheckBox.Checked)
			{
				foreach (IFigure figure in main.figures)
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
			if(argument >= min && argument <= max)
			{
				return true;
			}
			return false;
		}

		/// <summary>
		/// Валидация для полей площади
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SurfaceFirstTextBox_Validating(object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (!BlankFieldChecking(out errorMsg))
			{
				SearchButton.Enabled = false;
				SetError(SurfaceFirstTextBox,SurfaceSecondTextBox, errorMsg, sender, e);
			}
			else
			{
				SearchButton.Enabled = true;
				errorMsg = "";
				SetError(SurfaceFirstTextBox, SurfaceSecondTextBox, errorMsg, sender, e);
			}
		}

		/// <summary>
		/// Валидация для полей периметра
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void PerimeterFirstTextBox_Validating(object sender, CancelEventArgs e)
		{
			string errorMsg;
			if (!BlankFieldChecking(out errorMsg))
			{
				SearchButton.Enabled = false;
				SetError(PerimeterFirstTextBox, PerimeterSecondTextBox, errorMsg, sender, e);
			}
			else
			{
				SearchButton.Enabled = true;
				errorMsg = "";
				SetError(PerimeterFirstTextBox, PerimeterSecondTextBox, errorMsg, sender, e);
			}
		}

		/// <summary>
		/// Запрет на ввод всего проме цифр и backspace
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SurfaceFirstTextBox_KeyPress(object sender, KeyPressEventArgs e)
		{
			if (!(Char.IsDigit(e.KeyChar)))
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
