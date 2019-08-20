﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model.Interfaces;

namespace View
{
	public class AddingEventArg : EventArgs
	{
		public IFigure Figure { get; }

		public AddingEventArg(IFigure figure)
		{
			Figure = figure;
		}
	}
}