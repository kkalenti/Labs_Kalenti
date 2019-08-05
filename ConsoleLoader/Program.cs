using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using Model;

namespace ConsoleLoader
{
	// TODO: RSDN, XML
	class Program
	{
		//TODO: Используй var, там, где понятен тип, так получается код чище done
		/// <summary>
		/// Добавление круга в список
		/// </summary>
		/// <param name="figures"> Список фигур </param>
		public static void CircleToList(List<IFigure> figures)
		{
			//TODO: Дубль done
			var radius = DoubleInput("Введите радиус круга:");

			IFigure circle = new Circle(radius);
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

		public static double DoubleInput(string message)
		{
			while (true)
			{
				try
				{
					//TODO: Неправильно сделан ввод, получается, что если пользователь накосячит
					//TODO: во втором параметре, то придётся вводить и первый, а это не правильно! done

					//TODO: Дубль done
					Console.WriteLine(message);
					var value = Convert.ToDouble(Console.ReadLine());

					if (value <= 0)
					{
						throw new ArgumentException();
					}

					return value;
				} //TODO: Неправильно обрабатывать по базовому исключению - надо конкретизировать тип исключения done
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
			foreach (IFigure i in figures)
			{
				i.ShowDescription();
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

		//TODO: RSDN
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
					//TODO: Работает только с NumPad-овскими клавишами done
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
