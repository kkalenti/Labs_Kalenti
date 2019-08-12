using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using Model.Interfaces;
using System.Runtime.Serialization;

namespace Model
{
	[DataContract]
	public class Rectangle : IFigure
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

		private double _width;
		/// <summary>
		/// Ширина
		/// </summary>
		[DataMember]
		public double Width
		{
			get => _width;
			set => _width = value;
		}

		private double _length;
		/// <summary>
		/// Длинна
		/// </summary>
		[DataMember]
		public double Length
		{
			get => _length;
			set => _length = value;
		}

		/// <summary>
		/// Описание фигуры
		/// </summary>
		public string Description { get; }

		//TODO: XML done
		/// <summary>
		/// Конструктор по-умолчанию для работы XML сериализации
		/// </summary>
		public Rectangle()	{}

		//TODO: XML done
		/// <summary>
		/// Конструктор для объекта "Прямоугольник"
		/// </summary>
		/// <param name="width">Ширина прямоугольника</param>
		/// <param name="length">Длина прямоугольника</param>
		public Rectangle(double width, double length)
		{
			const int valueAlignment = 4;
			if (width <= 0 || Double.IsNaN(width) || Double.IsInfinity(width)
				|| length <= 0 || Double.IsNaN(length) || Double.IsInfinity(length))
			{
				//TODO: Сообщение некорректно, т.к. значение может и не вводиться. done
				throw new ArgumentException();
			}

			Width = width;
			Length = length;

			Surface = width * length;
			Perimeter = 2 * width + 2 * length;
			Description = $"Прямоугольник, ширина: {Width}, длина: {Length}," +
			              $" площадь: {Surface,valueAlignment:F3}, периметр: {Perimeter,valueAlignment:F3}";
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
