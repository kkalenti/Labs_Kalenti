using System;
using System.Collections.Generic;
using System.ComponentModel;
using Model.Interfaces;
using System.Windows.Forms;

namespace View
{
	/// <summary>
	/// Форма для поиска фигур
	/// </summary>
	public partial class FindingForm : Form
	{

		private readonly Dictionary<TextBox, Tuple<TextBox, TextBox>> _textBoxesDictionary;

		/// <summary>
		/// Ссылка на список фигур из  MainForm
		/// </summary>
		private BindingList<IFigure> Figures { get; }

		/// <summary>
		/// Список найденых фигур
		/// </summary>
		private BindingList<IFigure> FindingList { get; } = new BindingList<IFigure>();

		/// <summary>
		/// Конструктор формы поиска
		/// </summary>
		public FindingForm(BindingList<IFigure> figures)
		{
			InitializeComponent();
			Figures = figures;

			FigureGrid.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
			FigureGrid.DataSource = FindingList;

			_textBoxesDictionary = new Dictionary<TextBox, Tuple<TextBox, TextBox>>
			{
				[PerimeterFirstTextBox] = 
					new Tuple<TextBox, TextBox>(PerimeterFirstTextBox, PerimeterSecondTextBox),
				[SurfaceFirstTextBox] = 
					new Tuple<TextBox, TextBox>(SurfaceFirstTextBox, SurfaceSecondTextBox)
			};
		}

		//TODO: Зачем свойство? done
		/// <summary>
		/// Все поля прошли валидацию
		/// </summary>
		private bool _isValidated;

		/// <summary>
		/// Обработка кнопки поиска подходящих объектов
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SearchButton_Click(object sender, EventArgs e)
		{
			if (!_isValidated) return;

			
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
			//TODO: Возможна генерация исключения при конвертации done
			if (!double.TryParse(SurfaceFirstTextBox.Text, out var surfaceFirst) ||
			    !double.TryParse(SurfaceSecondTextBox.Text, out var surfaceSecond) ||
			    !double.TryParse(PerimeterFirstTextBox.Text, out var perimeterFirst) ||
			    !double.TryParse(PerimeterSecondTextBox.Text, out var perimeterSecond)) return;

			if (IsBetween(surfaceFirst, surfaceSecond, figure.Surface) &&
			    IsBetween(perimeterFirst, perimeterSecond, figure.Perimeter))
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
		/// <returns>true если <see cref="argument"/> пренадлежит промежутку</returns>
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
			//TODO: Дубль, решается следующим образом:
			//На уровне класса создаёшь словарь
			//readonly Dictionary<TextBox, Tuple<TextBox, TextBox>> _textBoxesDictionary =
			//	new Dictionary<TextBox, Tuple<TextBox, TextBox>>
			//	{
			//		[PerimeterFirstTextBox] =
			//			new Tuple<TextBox, TextBox>(PerimeterFirstTextBox, PerimeterSecondTextBox),
			//		[SurfaceFirstTextBox] = new Tuple<TextBox, TextBox>(SurfaceFirstTextBox, SurfaceSecondTextBox),
			//	};
			//TODO: Дальше подписываешь оба текстбокса на один обработчик, а в обработчике
			//TODO: дёргаешь текстбоксы из словаря по sender-y done

			// TODO: RSDN
			if (sender is TextBox selectedTextBox)
			{
				e.Cancel = IsCanceled(_textBoxesDictionary[selectedTextBox].Item1, 
					_textBoxesDictionary[selectedTextBox].Item2, out var errorMsg);

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
				_isValidated = IsValueGapValid(firstField.Text, secondField.Text, out errorMsg);
				return !_isValidated;
			}

			_isValidated = false;
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
		/// <returns>true если значение первой строки меньше
		/// или равно значению второй строки</returns>
		/// TODO: RSDN
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
