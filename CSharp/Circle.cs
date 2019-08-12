using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
using System.Xml.Serialization;
using System.Runtime.Serialization;

namespace Model
{
	/// <summary>
	/// Класс для кругов
	/// </summary>
	[DataContract]
	public class Circle : IFigure
	{
		private double _surface;
		/// <summary>
		/// Площадь фигуры
		/// </summary>
		[DataMember]
		public double Surface
		{
			get => _surface;
			set => _surface = value;
		}

		private double _perimeter;
		/// <summary>
		/// Периметр фигуры
		/// </summary>
		[DataMember]
		public double Perimeter
		{
			get => _perimeter;
			set => _perimeter = value;
		}


		private double _radius;
		[DataMember]
		/// <summary>
		/// Радиус фигуры
		/// </summary>
		public double Radius
		{
			get => _radius;
			set => _radius = value;
		}

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
			if (radius <= 0 || double.IsNaN(radius) || double.IsInfinity(radius))
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