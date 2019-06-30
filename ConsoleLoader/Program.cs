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
		static void Main(string[] args)
		{
			try
			{
				Console.WriteLine("Введите радиус круга:");
				double radius = Convert.ToDouble(Console.ReadLine());

				if (radius <= 0)
				{
					throw new ArgumentException("Введенное значение меньше или равно 0");
				}

				IFigure first = new Circle(radius);
				Console.WriteLine("Площадь круга: {0}", first.Surface);
				Console.WriteLine("Периметр круга: {0}", first.Perimeter);
			}
			catch (ArgumentException ex)
			{
				Console.WriteLine(ex.Message);
			}
			catch(FormatException ex)
			{
				Console.WriteLine(ex.Message);
			}
			Console.Clear();



			Console.ReadKey();
		}
	}
}
