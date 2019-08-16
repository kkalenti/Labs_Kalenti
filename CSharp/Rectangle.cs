using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;
//TODO: Некорректный namespace - посмотри настройки проекта
namespace Model
{
	[Serializable]
	public class Rectangle : IFigure
	{
		/// <summary>
		/// Площадь фигуры
		/// </summary>
		public double Surface { get; }

		/// <summary>
		/// Периметр фигуры
		/// </summary>
		public double Perimeter { get; }

		/// <summary>
		/// Ширина
		/// </summary>
		public double Width { get; }

		/// <summary>
		/// Длинна
		/// </summary>
		public double Length { get; }

		/// <summary>
		/// Описание фигуры
		/// </summary>
		public string Description { get; }

		/// <summary>
		/// Конструктор по-умолчанию для работы XML сериализации
		/// </summary>
		public Rectangle()	{}

		/// <summary>
		/// TODO: некорректный комментарий
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
				throw new ArgumentException();
			}

			Width = width;
			Length = length;
			//TODO: Не совсем удачная с точки зрения масштабирования модель, т.к. есть 
			//TODO: вероятность, что я не вызову никогда эти свойства, а время на их расчёт
			//TODO: уже потратится. А если их будет 100000000000 (много?)
			Surface = width * length;
			Perimeter = 2 * width + 2 * length;
			//TODO: Длинная строка
			Description = $"Прямоугольник, ширина: {Width}, длина: {Length}," +
			              $" площадь: {Surface,valueAlignment:F3}, периметр: {Perimeter,valueAlignment:F3}";
		}

		/// <summary>
		/// Вывод информации о фигуре
		/// </summary>
		public void ShowDescription()
		{
			Console.WriteLine(Description);
		}
	}
}
