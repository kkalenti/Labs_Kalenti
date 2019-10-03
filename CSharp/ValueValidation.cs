using System;
//TODO: using done

namespace Model
{
	//TODO: XML done
	/// <summary>
	/// Класс для проверок
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
