using System;

namespace Model
{
	/// <summary>
	/// Вспомогательный класс для валидации
	/// </summary>
	public class ValueValidation
	{
		/// <summary>
		/// Выбрасывает исключение если число меньше нуля
		/// </summary>
		/// <param name="value">Проверяемая величина</param>
		/// <param name="message">Название передаваемой переменной</param>
		public static void IsPositive(double value, string message)
		{
			if (double.IsNaN(value))
			{
				throw new ArgumentException(message + " is not a number");
			}
			if (double.IsInfinity(value))
			{
				throw new ArgumentException(message + " is infinity");
			}
			if (value <= 0)
			{
				throw new ArgumentException(message + " <= 0");
			}
		}
	}
}
