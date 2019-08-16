//TODO: Некорректный namespace - посмотри настройки проекта
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
		string Description { get; }

		/// <summary>
		/// Вывод информации о фигуре
		/// </summary>
		void ShowDescription();
	}
}
