using System;
//TODO: using
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
	//TODO: XML
	[DataContract]
	public class Rectangle : IFigure
	{
		// TODO: nameof
		/// <summary>
		/// Имя фигуры
		/// </summary>
		public string Name => "Rectangle";
		//TODO: XML
		private Lazy<double> _surface;
		/// <summary>
		/// Площадь фигуры
		/// </summary>
		public double Surface => _surface.Value;
		//TODO: XML
		private Lazy<double> _perimeter;
		/// <summary>
		/// Периметр фигуры
		/// </summary>
		public double Perimeter => _perimeter.Value;
		//TODO: XML
		private double _width;
		/// <summary>
		/// Ширина
		/// </summary>
		[DataMember]
		public double Width
		{
			get => _width;
			set
			{
				// TODO: nameof
				ValueValidation.IsPositive(value, "Width");
				_width = value;
				CalculationInit();
			}

		}
		//TODO: XML
		private double _length;
		/// <summary>
		/// Длинна
		/// </summary>
		[DataMember]
		public double Length
		{
			get => _length;
			set
			{
				// TODO: nameof
				ValueValidation.IsPositive(value, "Length");
				_length = value;
				CalculationInit();
			}
		}

		//TODO: Название метода не отражает назначения
		/// <summary>
		/// Инициализация полей площади и периметра
		/// </summary>
		private void CalculationInit()
		{
			if (_surface == null || _perimeter == null)
			{
				_surface = new Lazy<double>(() => Width * Length);
				_perimeter = new Lazy<double>(() => 2 * Width + 2 * Length);
			}
		}

		/// <summary>
		/// Описание фигуры
		/// </summary>
		/// // TODO: RSDN
		public string Description {
			get
			{
				const int valueAlignment = 4;
				return  $"Прямоугольник, ширина: {Width}," +
							$" длина: {Length}," +
							$" площадь: {Surface,valueAlignment:F3}," +
							$" периметр: {Perimeter,valueAlignment:F3}";
			}
		}

		//TODO: XML <see cref...
		/// <summary>
		/// Конструктор по-умолчанию для работы XML сериализации
		/// </summary>
		public Rectangle()
		{}

		//TODO: Нужен ли этот конструктор, если можно сразу инициализировать свойства
		/// <summary>
		/// Конструктор для объекта <see cref="Rectangle"/>
		/// </summary>
		/// <param name="width">Ширина прямоугольника</param>
		/// <param name="length">Длина прямоугольника</param>
		public Rectangle(double width, double length)
		{
			Width = width;
			Length = length;
		}
	}
}
