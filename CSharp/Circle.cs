using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using System.Xml.Serialization;

namespace Model
{	
	[Serializable]
	/// <summary>
	/// Класс для кругов
	/// </summary>
	public class Circle : IFigure
	{
		[XmlAttribute]
		/// <summary>
		/// Площадь фигуры
		/// </summary>
		public double Surface { get; }

		[XmlAttribute]
		/// <summary>
		/// Периметр фигуры
		/// </summary>
		public double Perimeter { get; }

		[XmlAttribute]
		/// <summary>
		/// Радиус фигуры
		/// </summary>
		public double Radius { get; }

		/// <summary>
		/// Описание фигуры
		/// </summary>
		public string Description { get; }

		//TODO: XML done
		/// <summary>
		/// Конструктор по-умолчанию для работы XML сериализации
		/// </summary>
		public Circle() { }

		//TODO: XML done
		/// <summary>
		/// Конструктор для объектов "Круг"
		/// </summary>
		/// <param name="radius">Радиус круга</param>
		public Circle(double radius)
		{
			const int valueAlignment = 4;
			if (radius <= 0)
			{
				//TODO: Сообщение некорректно, т.к. значение может и не вводиться. Done
				throw new ArgumentException();
			}

			Radius = radius;
			Surface = 2 * Math.PI * radius;
			Perimeter = Math.PI * Radius * Radius;
			Description = $"Круг, радиус: {Radius}, площадь: {Surface,valueAlignment:F3}," +
			              $" периметр: {Perimeter,valueAlignment:F3}";
		}

		//TODO: Правильнее сделать свойством done
		/// <summary>
		/// Вывод информации о фигуре
		/// </summary>
		public void ShowDescription()
		{
			//TODO: Переделай в интерполяционную строку - лучше будет смотреться done
			Console.WriteLine(Description);
		}
	}
}