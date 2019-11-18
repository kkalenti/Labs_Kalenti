using System;
using Model.Interfaces;

namespace View
{
	/// <summary>
	/// Снабжает данными события в форме добавления объектов
	/// </summary>
	public class AddingEventArg : EventArgs
	{
		/// <summary>
		/// Передаваемая фигура
		/// </summary>
		public IFigure Figure { get; }

		/// <summary>
		/// Конструктор класса <see cref="AddingEventArg"/>
		/// </summary>
		/// <param name="figure">Фигура</param>
		public AddingEventArg(IFigure figure)
		{
			Figure = figure;
		}
	}
}
