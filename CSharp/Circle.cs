using System;
using Model.Interfaces;
using System.Runtime.Serialization;

namespace Model
{
	/// <summary>
	/// Представляет геометрическую фигуру типа круг
	/// </summary>
	[DataContract]
	public class Circle : IFigure
	{
        /// <summary>
        /// Lazy поле для свойства <see cref="Surface"/>
        /// </summary>
		private Lazy<double> _surface;

		/// <summary>
		/// Площадь фигуры
		/// </summary>
		public double Surface => _surface.Value;

        /// <summary>
        /// Lazy поле для свойства <see cref="Perimeter"/>
        /// </summary>
        private Lazy<double> _perimeter;

		/// <summary>
		/// Периметр фигуры
		/// </summary>
		public double Perimeter => _perimeter.Value;

        /// <summary>
        /// Приватное поле для свойства <see cref="Radius"/>
        /// </summary>
		private double _radius;

		/// <summary>
		/// Радиус фигуры
		/// </summary>
		[DataMember]
		public double Radius
		{
			get => _radius;
			set
			{
				ValueValidation.IsPositive(value, nameof(Radius));
				_radius = value;

                if (_surface != null && _perimeter != null) return;

                _surface = new Lazy<double>(() => 2 * Math.PI * Radius);
                _perimeter = new Lazy<double>(() => Math.PI * Radius * Radius);
            }
		}

		/// <summary>
		/// Возвращает текстовое описание фигуры
		/// </summary>
		public string FigureDescription {
			get
			{
				const int valueAlignment = 4;
				return $"Круг, радиус: {Radius}," +
				       $" площадь: {Surface,valueAlignment:F3}," +
				       $" периметр: {Perimeter,valueAlignment:F3}";
			}

		}

        /// <summary>
        /// Конструктор для класса <see cref="Circle"/>
        /// необходим для работы XML сериализации
        /// </summary>
        public Circle()
		{}
	}
}