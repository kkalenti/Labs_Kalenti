using System;
using System.Collections.Generic;
using System.Linq;

//TODO: using
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using Model;

namespace ConsoleLoader
{
	/// <summary>
	/// Класс для основной функциональности программы 
	/// </summary>
	internal class Program
	{
		/// <summary>
		/// Добавление круга в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		public static void CircleToList(List<IFigure> figures)
		{
			var radius = DoubleInput("Введите радиус круга:");

			IFigure circle = new Circle();
			figures.Add(circle);
		}

		/// <summary>
		/// Добавление прямугольника в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		public static void RectangleToList(List<IFigure> figures)
		{
			var width = DoubleInput("Введите ширину прямоугольника:");
			var length = DoubleInput("Введите длину прямоугольника:");

			IFigure rectangle = new Rectangle(width, length);
			figures.Add(rectangle);
		}

		//TODO: XML
		public static double DoubleInput(string message)
		{
			while (true)
			{
				try
				{
					Console.WriteLine(message);
					var value = Convert.ToDouble(Console.ReadLine());

					if (value <= 0)
					{
						throw new ArgumentException();
					}

					return value;
				}
				//TODO: Почему в одном случае сообщение формируешь в исключении, а во втором тут?
				catch (ArgumentException)
				{
					Console.WriteLine("Введенное значение меньше или равно 0");
				}
				catch (FormatException formatEx)
				{
					Console.WriteLine(formatEx.Message);
				}
			}
		}

		/// <summary>
		/// Вывод элементов списка
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		public static void ShowList(List<IFigure> figures)
		{
			//TODO: var
			foreach (IFigure i in figures)
			{
				Console.WriteLine(i.Description);
			}
			Console.ReadKey();
		}

		/// <summary>
		/// Удаление элемента списка
		/// </summary>
		/// <param name="figures">Список фигур </param>
		public static void DeleteElement(List<IFigure> figures)
		{
			try
			{
				Console.WriteLine("Введите номер элемента:");
				var index = Convert.ToInt32(Console.ReadLine());

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
		public static void ShowMenu()
		{
			Console.WriteLine("Выберите действие:");
			Console.WriteLine("1.Добавить круг в список");
			Console.WriteLine("2.Добавить прямоугольник в список");
			Console.WriteLine("3.Удалить элемент списка");
			Console.WriteLine("4.Вывести список");
			Console.WriteLine("Esc.Выйти из программы");
		}

		private static void Main(string[] args)
		{
			var figures = new List<IFigure>();
			while (true)
			{
				Console.WriteLine("Количество элементов в списке: {0}", figures.Count());
				ShowMenu();
				var key = Console.ReadKey(false).Key;
				switch (key)
				{
					case ConsoleKey.NumPad1:
					case ConsoleKey.D1:
						Console.Clear();
						CircleToList(figures);
						break;
					case ConsoleKey.NumPad2:
					case ConsoleKey.D2:
						Console.Clear();
						RectangleToList(figures);
						break;
					case ConsoleKey.NumPad3:
					case ConsoleKey.D3:
						Console.Clear();
						DeleteElement(figures);
						break;
					case ConsoleKey.NumPad4:
					case ConsoleKey.D4:
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
