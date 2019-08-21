﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using System.Windows.Forms;
using Model;

namespace View
{
	/// <summary>
	/// Форма для поиска фигур
	/// </summary>
	public partial class FindingForm : Form
	{
		/// <summary>
		/// Ссылка на список фигур из  MainForm
		/// </summary>
		private BindingList<IFigure> Figures { get; }

		/// <summary>
		/// Список найденых фигур
		/// </summary>
		private BindingList<IFigure> FindingList { get; } = new BindingList<IFigure>();

		//TODO: Неправильно в дочерней форме хранить указатель на родительскую! Убирай нах. done
		//TODO: XML done
		/// <summary>
		/// Конструктор формы поиска
		/// </summary>
		public FindingForm(BindingList<IFigure> figures)
		{
			InitializeComponent();
			Figures = figures;

			FigureGrid.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
			FigureGrid.DataSource = FindingList;
		}

		/// <summary>
		/// Все поля прошли валидацию
		/// </summary>
		private bool IsValidated { get; set; }

		/// <summary>
		/// Обработка кнопки поиска подходящих объектов
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SearchButton_Click(object sender, EventArgs e)
		{
			if (!IsValidated) return;

			
			if (!RectangleCheckBox.Checked && !CircleCheckBox.Checked) return;

			FindingList.Clear();
			foreach (var figure in Figures)
			{
				if (figure is Model.Rectangle && RectangleCheckBox.Checked ||
				    figure is Model.Circle && CircleCheckBox.Checked)
				{
					AddToGrid(figure);
				}
			}
		}

		/// <summary>
		/// Добавление фигуры в список
		/// </summary>
		/// <param name="figure">Фигура</param>
		private void AddToGrid(IFigure figure)
		{
			if (IsBetween(Convert.ToDouble(SurfaceFirstTextBox.Text),
				Convert.ToDouble(SurfaceSecondTextBox.Text), figure.Surface) &&
				IsBetween(Convert.ToDouble(PerimeterFirstTextBox.Text),
				Convert.ToDouble(PerimeterSecondTextBox.Text), figure.Perimeter))
			{
				FindingList.Add(figure);
			}
		}

		/// <summary>
		/// Проверка на вхождение в интервал
		/// </summary>
		/// <param name="min">Минимум</param>
		/// <param name="max">Максимум</param>
		/// <param name="argument">Аргумент для проверки</param>
		/// <returns></returns>
		private bool IsBetween(double min, double max, double argument)
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
			
			e.Cancel = IsCanceled(SurfaceFirstTextBox, SurfaceSecondTextBox,
			out var errorMsg);

			if (sender is TextBox selectedTextBox)
			{
				SetError(selectedTextBox, errorMsg);
			}
		}

		/// <summary>
		/// Валидация для полей периметра
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void PerimeterFirstTextBox_Validating(object sender, CancelEventArgs e)
		{
			//TODO: Дубль done
			e.Cancel = IsCanceled(PerimeterFirstTextBox, PerimeterSecondTextBox,
				out var errorMsg);

			if (sender is TextBox selectedTextBox)
			{
				SetError(selectedTextBox, errorMsg);
			}

		}

		/// <summary>
		/// Устанавливает ошибку для текстбокса
		/// </summary>
		/// <param name="selectedTextBox"></param>
		/// <param name="errorMsg"></param>
		private void SetError(TextBox selectedTextBox, string errorMsg)
		{
			selectedTextBox.Select(0, selectedTextBox.Text.Length);
			errorProvider.SetError(selectedTextBox, errorMsg);
		}

		/// <summary>
		/// Возвращает true если все поля заполнены правильно
		/// </summary>
		/// <param name="firstField">Первое поле</param>
		/// <param name="secondField">Второе поле</param>
		/// <param name="errorMsg"></param>
		private bool IsCanceled(TextBox firstField, TextBox secondField, out string errorMsg)
		{
			var isFilled = IsFieldsFilled(out errorMsg);
			SetErrorForAll(errorMsg);

			if (isFilled)
			{
				IsValidated = IsValueGapValid(firstField.Text, secondField.Text, out errorMsg);
				return !IsValidated;
			}

			IsValidated = false;
			return false;
		}

		/// <summary>
		/// Запрет на ввод всего проме цифр и backspace
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SurfaceFirstTextBox_KeyPress(object sender, KeyPressEventArgs e)
		{
			if (char.IsDigit(e.KeyChar)) return;

			if (e.KeyChar != (char)Keys.Back)
			{
				e.Handled = true;
			}
		}


		/// <summary>
		/// Устанавливает текст ошибки для всех текствоксов
		/// </summary>
		/// <param name="errorMsg">Сообщение ошибки</param>
		private void SetErrorForAll(string errorMsg)
		{
			this.errorProvider.SetError(SurfaceFirstTextBox, errorMsg);
			this.errorProvider.SetError(SurfaceSecondTextBox, errorMsg);
			this.errorProvider.SetError(PerimeterFirstTextBox, errorMsg);
			this.errorProvider.SetError(PerimeterSecondTextBox, errorMsg);
		}

		/// <summary>
		/// Возвращает false если один из textbox-ов не заполнен
		/// </summary>
		/// <param name="errorMessage">Текст ошибки</param>
		/// <returns></returns>
		private bool IsFieldsFilled(out string errorMessage)
		{
			if (string.IsNullOrEmpty(SurfaceFirstTextBox.Text) ||
			    string.IsNullOrEmpty(SurfaceSecondTextBox.Text) ||
			    string.IsNullOrEmpty(PerimeterFirstTextBox.Text) ||
			    string.IsNullOrEmpty(PerimeterSecondTextBox.Text))
			{
				errorMessage = "All fields must be filled in";
				return false;
			}
			errorMessage = "";
			return true;
		}

		/// <summary>
		/// Возвращает true если
		/// значение первой строки меньше или равно значению второй
		/// </summary>
		/// <param name="firstStr">Первая строка</param>
		/// <param name="secondStr">Вторая строка</param>
		/// <param name="errorMessage">Текст ошибки</param>
		/// <returns></returns>
		private static bool IsValueGapValid(string firstStr, string secondStr, out string errorMessage)
		{
			if (double.TryParse(firstStr, out var firstResult)
			    && double.TryParse(secondStr, out var secondResult))
			{
				if (firstResult > secondResult)
				{
					errorMessage = "Second value must be more or equal to the first";
					return false;
				}

				errorMessage = "";
				return true;
			}

			errorMessage = "Values are incorrect";
			return false;
		}
	}
}
