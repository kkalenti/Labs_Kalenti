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
		public event EventHandler<AddingEventArg> AddFigure;

		public event EventHandler<AddingEventArg> ModifyFigure;

		/// <summary>
		/// Конструктор формы добавления элементоа
		/// </summary>
		//TODO: Неправильно в дочерней форме хранить указатель на родительскую! Убирай нах. done
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
			this.Text = "Modifying";
			objectControl.Object = figure;
			objectControl.ReadOnly = false;
			AddButton.Enabled = false;
			AddButton.Visible = false;
			ModifyButton.Enabled = true;
			ModifyButton.Visible = true;
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
			if (objectControl.IsAddingEnable)
			{
				AddFigure?.Invoke(this, new AddingEventArg(objectControl.Object));
				this.Close();
			}
		}

		/// <summary>
		/// Кнопка изменения данных о фигуре
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void ModifyButton_Click(object sender, EventArgs e)
		{
			if (objectControl.IsAddingEnable)
			{
				ModifyFigure?.Invoke(this, new AddingEventArg(objectControl.Object));
				this.Close();
			}
		}
	}
}
