using System;
using System.Collections.Generic;
using System.ComponentModel;
using Model.Interfaces;
using System.Windows.Forms;
using  System.Runtime.Serialization;
using System.Xml;

namespace View
{
	/// <summary>
	/// Основная форма
	/// </summary>
	public partial class MainForm : Form
	{
		/// <summary>
		/// Список фигур
		/// </summary>
		/// //TODO: зачем свойство? done
		private BindingList<IFigure> _figures = new BindingList<IFigure>();

		/// <summary>
		/// Конструктор главной формы
		/// </summary>
		public MainForm()
		{
			InitializeComponent();
			FigureGrid.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
			FigureGrid.DataSource = _figures;
		}

		/// <summary>
		/// Конструктор главной формы с входным аргументом
		/// </summary>
		/// <param name="args">Путь к входному файлу</param>
		public MainForm(string[] args)
		{
			InitializeComponent();
			FiguresDeserializing(args[0]);
			FigureGrid.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
			FigureGrid.DataSource = _figures;
		}

		/// <summary>
		/// Обработка кнопки для открытия формы добавления фигуры
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void AddButton_Click(object sender, EventArgs e)
		{
			var adding = new AddingForm();
			adding.AddFigure += AddToListHandler;
			adding.ShowDialog();
		}

		/// <summary>
		/// Кнопка вызова формы изменения данных о фигуре
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void ModifyButton_Click(object sender, EventArgs e)
		{
			//TODO: invert done
			if (FigureGrid.SelectedRows.Count <= 0) return;

			var figure = _figures[FigureGrid.SelectedRows[0].Index];
			var modify = new AddingForm(figure);
			modify.ModifyFigure += ModifyElementHandler;
			modify.ShowDialog();
		}

		/// <summary>
		/// Обработка кнопки удаления выделенных строк
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RemoveButton_Click(object sender, EventArgs e)
		{
			foreach (DataGridViewRow row in FigureGrid.SelectedRows)
			{
				_figures.RemoveAt(row.Index);
			}
		}

		/// <summary>
		/// Изменение фигуры
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void ModifyElementHandler(object sender, AddingEventArg e)
		{
			var elementIndex = FigureGrid.SelectedRows[0].Index;
			_figures.RemoveAt(elementIndex);
			_figures.Insert(elementIndex, e.Figure);
		}

#if DEBUG
		/// <summary>
		/// Генерация рандомной фигуры
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RandomObjectButton_Click(object sender, EventArgs e)
		{
			var rand = new Random();
			var figureNumber = rand.Next(0, 2);
			switch (figureNumber)
			{
				case 0:
					_figures.Add(new Model.Circle()
					{
						Radius = rand.Next(1, 20)
					});
					break;

				case 1:
					_figures.Add(new Model.Rectangle()
					{
						Width = rand.Next(1, 20),
						Length = rand.Next(1, 20)
					});
					break;
				default:
					break;
			}
		}
#endif

		/// <summary>
		/// Обработка кнопки для открытия формы поиска
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void FindObjectButton_Click(object sender, EventArgs e)
		{
			var finding = new FindingForm(_figures);
			finding.Show();
		}

		/// <summary>
		/// Обработка кнопки для сохранения данных
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SaveButton_Click(object sender, EventArgs e)
		{
			// TODO: Дубль
			//TODO: Нахрен тебе на уровне формы всё время его хранить? done

			var saveFile = new SaveFileDialog {Filter = "Xml file|*.kk"};
			if (saveFile.ShowDialog() == DialogResult.Cancel)
				return;

			var filename = saveFile.FileName;

			var writer = new DataContractSerializer(typeof(BindingList<IFigure>), 
				new List<Type> { typeof(Model.Rectangle), typeof(Model.Circle) });
			var settings = new XmlWriterSettings {Indent = true};

			using (var fs = XmlWriter.Create(filename, settings))
			{
				writer.WriteObject(fs, _figures);
			}

		}

		/// <summary>
		/// Выделение всей выбранной строки
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void FigureGrid_SelectionChanged(object sender, EventArgs e)
		{
			if (FigureGrid.CurrentCell != null)
			{
				FigureGrid.Rows[FigureGrid.CurrentCell.RowIndex].Selected = true;
				MyControl.Object = _figures[FigureGrid.SelectedRows[0].Index];
				MyControl.ReadOnly = true;
			}
			else
			{
				MyControl.ClearFields();
			}
		}

		/// <summary>
		/// Открытие и десериализация выбранного файла
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void OpenFileButton_Click(object sender, EventArgs e)
		{
			//TODO: Дубль
			var openFile = new OpenFileDialog {Filter = "Xml file|*.*"};
			//TODO: Нахрен тебе на уровне формы всё время его хранить? done
			//TODO: При открытии файла в имени написан openFileDialog1 - это не правильно.
			if (openFile.ShowDialog() == DialogResult.Cancel)
				return;

			var filename = openFile.FileName;

			FiguresDeserializing(filename);
		}

		/// <summary>
		/// Десериализация данных из файла
		/// </summary>
		/// <param name="filename">Имя файла</param>
		private void FiguresDeserializing(string filename)
		{
			var reader = new DataContractSerializer(typeof(BindingList<IFigure>),
				new List<Type> { typeof(Model.Rectangle), typeof(Model.Circle) });

			try
			{
				using (var fs = XmlReader.Create(filename))
				{
					//TODO:Не отработана десериализация сломанного файла done
					_figures = (BindingList<IFigure>) reader.ReadObject(fs);
				}
			}
			catch (SerializationException exception)
			{
				MessageBox.Show("Недопустимый для чтения файл", "Ошибка!",
					MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
			
			FigureGrid.DataSource = _figures;
		}

		//TODO: XML done
		/// <summary>
		/// Обработчик для добавления файла в список
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void AddToListHandler(object sender, AddingEventArg e)
		{
			_figures.Add(e.Figure);
		}
	}
}
