using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using Model;

namespace ConsoleLoader
{
	class Program
	{
		/// <summary>
		/// Добавление круга в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		static public void CircleToList(List<IFigure> figures)
		{
			try
			{
				Console.WriteLine("Введите радиус круга:");
				double radius = Convert.ToDouble(Console.ReadLine());

				IFigure circle = new Circle(radius);
				figures.Add(circle);
			}
			catch (Exception ex)
			{
				Console.WriteLine(ex.Message);
				Console.ReadKey();
			}
		}

		/// <summary>
		/// Добавление прямугольника в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		static public void RectangleToList(List<IFigure> figures)
		{
			try
			{
				Console.WriteLine("Введите ширину прямоугольника:");
				double width = Convert.ToDouble(Console.ReadLine());

				Console.WriteLine("Введите длину прямоугольника:");
				double length = Convert.ToDouble(Console.ReadLine());

				IFigure rectangle = new Rectangle(width, length);
				figures.Add(rectangle);
			}
			catch (Exception ex)
			{
				Console.WriteLine(ex.Message);
				Console.ReadKey();
			}
		}

		/// <summary>
		/// Вывод элементов списка
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		static public void ShowList(List<IFigure> figures)
		{
			foreach (IFigure i in figures)
			{
				i.GetDescription();
			}
			Console.ReadKey();
		}

		/// <summary>
		/// Удаление элемента списка
		/// </summary>
		/// <param name="figures">Список фигур </param>
		static public void DeleteElement(List<IFigure> figures)
		{
			try
			{
				Console.WriteLine("Введите номер элемента:");
				int index = Convert.ToInt32(Console.ReadLine());

				figures.RemoveAt(index);
			}
			catch (Exception ex)
			{
				Console.WriteLine(ex.Message);
				Console.ReadKey();
			}
		}

		/// <summary>
		/// Вывод меню программы
		/// </summary>
		static public void ShowMenu()
		{
			Console.WriteLine("Выберите действие:");
			Console.WriteLine("1.Добавить круг в список");
			Console.WriteLine("2.Добавить прямоугольник в список");
			Console.WriteLine("3.Удалить элемент списка");
			Console.WriteLine("4.Вывести список");
			Console.WriteLine("Esc.Выйти из программы");
		}


		static void Main(string[] args)
		{
			List<IFigure> figures = new List<IFigure>();
			while (true)
			{
				Console.WriteLine("Количество элементов в списке: {0}", figures.Count());
				ShowMenu();
				var key = Console.ReadKey(false).Key;
				switch (key)
				{
					case ConsoleKey.NumPad1:
						Console.Clear();
						CircleToList(figures);
						break;
					case ConsoleKey.NumPad2:
						Console.Clear();
						RectangleToList(figures);
						break;
					case ConsoleKey.NumPad3:
						Console.Clear();
						DeleteElement(figures);
						break;
					case ConsoleKey.NumPad4:
						Console.Clear();
						ShowList(figures);
						break;
					case ConsoleKey.Escape:
						return;
				}
				Console.Clear();
			}
		}
	}
}
