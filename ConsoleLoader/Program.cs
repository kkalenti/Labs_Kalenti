using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model;

namespace ConsoleLoader
{
	class Program
	{
		static void Main(string[] args)
		{
			Circle first = new Circle(15);

			Console.WriteLine("Площадь круга: {0}", first.CalculateSurface());
			Console.WriteLine("Периметр круга: {0}", first.CalculatePerimeter());

			Console.ReadKey();
		}
	}
}
