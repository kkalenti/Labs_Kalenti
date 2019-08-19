using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using Model;
using Model.Interfaces;
using System.Windows.Forms;
using System.IO;
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
		/// //TODO: RSDN done
		public List<IFigure> Figures { get; private set; } = new List<IFigure>();

		/// <summary>
		/// Конструктор главной формы
		/// </summary>
		//TODO: XML done
		public MainForm()
		{
			InitializeComponent();
		}

		/// <summary>
		/// Конструктор главной формы с входным аргументом
		/// </summary>
		/// <param name="args">Путь к входному файлу</param>
		public MainForm(string[] args)
		{
			InitializeComponent();
			OpenInputFile(args[0]);
		}

		/// <summary>
		/// Обработка кнопки для открытия формы добавления фигуры
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void AddButton_Click(object sender, EventArgs e)
		{
			var adding = new AddingForm()
			{
				Owner = this
			};
			adding.Show();
		}

		/// <summary>
		/// Кнопка вызова формы изменения данных о фигуре
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void ModifyButton_Click(object sender, EventArgs e)
		{
			if (FigureGrid.SelectedRows.Count > 0)
			{
				IFigure figure = Figures[FigureGrid.SelectedRows[0].Index];
				var modify = new AddingForm(figure)
				{
					Owner = this
				};
				modify.Show();
			}
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
				Figures.RemoveAt(row.Index);
				FigureGrid.Rows.Remove(row);
			}
		}

		/// <summary>
		/// Изменение фигуры
		/// </summary>
		/// <param name="figure">Фигура</param>
		public void ModifyElement(IFigure figure)
		{
			Figures.RemoveAt(FigureGrid.CurrentRow.Index);
			FigureGrid.Rows.Remove(FigureGrid.CurrentRow);
			FigureToList(figure);
		}

		/// <summary>
		/// Добавление фигуры в список и таблицу
		/// </summary>
		/// <param name="figure">Фигура</param>
		public void FigureToList(IFigure figure)
		{
			FigureGrid.DataSource = Figures;
			Figures.Add(figure);
		}

		/// <summary>
		/// Добавление фигуры в список
		/// </summary>
		/// <param name="figure">Фигура</param>
		public void FigureToGrid(IFigure figure)
		{
			if (figure is Model.Circle)
			{
				FigureGrid.Rows.Add("Circle", figure.Surface, figure.Perimeter);
			}
			else
			{
				FigureGrid.Rows.Add("Rectangle", figure.Surface, figure.Perimeter);
			}
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
			bool flag = rand.Next(0, 2) == 1;
			if(flag == true)
			{
				FigureToList(new Model.Circle(rand.Next(1, 20)));
			}
			else
			{
				FigureToList(new Model.Rectangle(rand.Next(1, 20), rand.Next(1, 20)));
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
			var finding = new FindingForm
			{
				Owner = this
			};
			finding.Show();
		}

		/// <summary>
		/// Обработка кнопки для сохранения данных
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void SaveButton_Click(object sender, EventArgs e)
		{
			saveFile.Filter = "Xml file|*.kk";
			if (saveFile.ShowDialog() == DialogResult.Cancel)
				return;
			var filename = saveFile.FileName;

			var writer = new DataContractSerializer(typeof(List<IFigure>), 
				new List<Type> { typeof(Model.Rectangle), typeof(Model.Circle) });

			var settings = new XmlWriterSettings {Indent = true};

			using (var fs = XmlWriter.Create(filename, settings))
			{
				writer.WriteObject(fs, Figures);
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
				MyControl.Object = Figures[FigureGrid.CurrentRow.Index];
				MyControl.ReadOnly = true;
			}
			else
			{
				MyControl.CleanFields();
			}
		}

		/// <summary>
		/// Открытие и десериализация выбранного файла
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void OpenFileButton_Click(object sender, EventArgs e)
		{
			openFile.Filter = "Xml file|*.kk";
			if (openFile.ShowDialog() == DialogResult.Cancel)
			{
				return;
			}
			var filename = openFile.FileName;

			FiguresDeserializing(filename);

			foreach (IFigure figure in Figures)
			{
				FigureToGrid(figure);
			}
		}


		/// <summary>
		/// Десериализация данных из файла
		/// </summary>
		/// <param name="filename">Имя файла</param>
		public void FiguresDeserializing(string filename)
		{
			var reader = new DataContractSerializer(typeof(List<IFigure>),
				new List<Type> { typeof(Model.Rectangle), typeof(Model.Circle) });

			using (var fs = XmlReader.Create(filename))
			{
				Figures = (List<IFigure>)reader.ReadObject(fs);
			}
		}

		/// <summary>
		/// Открытие входного файла
		/// </summary>
		/// <param name="filename">Имя файла</param>
		public void OpenInputFile(string filename)
		{
			FiguresDeserializing(filename);

			foreach (IFigure figure in Figures)
			{
				FigureToGrid(figure);
			}
		}
	}
}
