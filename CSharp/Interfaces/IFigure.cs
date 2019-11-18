using System.ComponentModel;

namespace Model.Interfaces
{
	/// <summary>
	/// Интерфейс для геометрических фигур
	/// </summary>
	public interface IFigure
    {
        /// <summary>
        /// Площадь фигуры
        /// </summary>
        /// <returns></returns>
        double Surface { get; }

		/// <summary>
		/// Периметр фигуры
		/// </summary>
		/// <returns></returns>
		double Perimeter { get; }

		/// <summary>
		/// Описание фигуры
		/// </summary>
		[Browsable(false)]
		string FigureDescription { get; }


	}
}
