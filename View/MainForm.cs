using System;
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
		public List<IFigure> figures = new List<IFigure>();

		public MainForm()
		{
			InitializeComponent();
		}

		private void AddButton_Click(object sender, EventArgs e)
		{
			AddingForm adding = new AddingForm(this);
			adding.Show();
		}

		private void RemoveButton_Click(object sender, EventArgs e)
		{
			foreach (DataGridViewRow row in FigureGrid.SelectedRows)
			{
				figures.RemoveAt(row.Index);
				FigureGrid.Rows.Remove(row);
			}
		}

		/// <summary>
		/// Добавление круга в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		public void CircleToList(double radius)
		{
			IFigure circle = new Model.Circle(radius);
			figures.Add(circle);
			FigureGrid.Rows.Add("Circle", circle.Surface, circle.Perimeter);
		}

		/// <summary>
		/// Добавление прямугольника в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		public void RectangleToList(double width, double length)
		{
			IFigure rectangle = new Model.Rectangle(width, length);
			figures.Add(rectangle);
			FigureGrid.Rows.Add("Rectangle", rectangle.Surface, rectangle.Perimeter);
		}

		//TODO: че сделать чтобы она не отображалась?
#if DEBUG
		private void RandomObjectButton_Click(object sender, EventArgs e)
		{
			Random rand = new Random();
			bool flag = rand.Next(0, 2) == 1;
			if(flag == true)
			{
				CircleToList(rand.Next(1, 20));
			}
			else
			{
				RectangleToList(rand.Next(1, 20), rand.Next(1, 20));
			}
		}
#endif

		private void FindObjectButton_Click(object sender, EventArgs e)
		{
			FindingForm finding = new FindingForm(this);
			finding.Show();
		}

		private void SaveButton_Click(object sender, EventArgs e)
		{
			foreach (IFigure figure in figures)
			{
				if(figure is Model.Rectangle)
				{
					XmlSerializer writer = new XmlSerializer(typeof(Model.Rectangle));
					using (FileStream file = new FileStream("C:\\Users\\kosti\\Desktop\\lessons\\Extra labs\\2\\persons.xml", FileMode.Append))
					{
						writer.Serialize(file, figure);
						file.Close();
					}
				}
				else
				{
					XmlSerializer writer = new XmlSerializer(typeof(Model.Circle));
					using (FileStream file = new FileStream("C:\\Users\\kosti\\Desktop\\lessons\\Extra labs\\2\\persons.xml", FileMode.Append))
					{
						writer.Serialize(file, figure);
						file.Close();
					}
				}
			}
		}
	}
}
