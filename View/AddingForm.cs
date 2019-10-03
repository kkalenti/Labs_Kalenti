using System;
using System.Windows.Forms;
using Model.Interfaces;

namespace View
{
	/// <summary>
	/// Форма для добавления объектов
	/// </summary>
	public partial class AddingForm : Form
	{
		/// <summary>
		/// Событие на добавление фигуры в список
		/// </summary>
		public event EventHandler<AddingEventArg> AddFigure;

		/// <summary>
		/// Событие на изменение фигуры в списке
		/// </summary>
		public event EventHandler<AddingEventArg> ModifyFigure;

		/// <summary>
		/// Конструктор формы добавления элементоа
		/// </summary>
		public AddingForm()
		{
			InitializeComponent();
			objectControl.ReadOnly = false;
		}

		/// <summary>
		/// Конструктор формы изменения элементов
		/// </summary>
		/// <param name="figure"></param>
		public AddingForm(IFigure figure)
		{
			InitializeComponent();
			Text = "Modifying";

			objectControl.Object = figure;
            objectControl.ReadOnly = false;

			EnableButton(AddButton, false);

			EnableButton(ModifyButton, true);
		}

		/// <summary>
		/// Отключает кнопку
		/// </summary>
		/// <param name="button"></param>
		/// <param name="enabled"></param>
		private void EnableButton(Button button, bool enabled)
		{
			button.Enabled = enabled;
			button.Visible = enabled;
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
			//TODO: invert done 
			if (!objectControl.IsAddingEnable) return;

			AddFigure?.Invoke(this, new AddingEventArg(objectControl.Object));
			this.Close();
		}

		/// <summary>
		/// Кнопка изменения данных о фигуре
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void ModifyButton_Click(object sender, EventArgs e)
		{
			//TODO: invert done
			if (!objectControl.IsAddingEnable) return;

			ModifyFigure?.Invoke(this, new AddingEventArg(objectControl.Object));
			this.Close();
		}
	}
}
