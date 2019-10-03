﻿namespace View
{
	partial class MainForm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.FigureGroupBox = new System.Windows.Forms.GroupBox();
			this.OpenFileButton = new System.Windows.Forms.Button();
			this.MyControl = new View.ObjectControl();
			this.ModifyButton = new System.Windows.Forms.Button();
			this.SaveButton = new System.Windows.Forms.Button();
			this.RandomObjectButton = new System.Windows.Forms.Button();
			this.FindObjectButton = new System.Windows.Forms.Button();
			this.FigureGrid = new System.Windows.Forms.DataGridView();
			this.RemoveButton = new System.Windows.Forms.Button();
			this.AddButton = new System.Windows.Forms.Button();
			this.FigureGroupBox.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.FigureGrid)).BeginInit();
			this.SuspendLayout();
			// 
			// FigureGroupBox
			// 
			this.FigureGroupBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.FigureGroupBox.Controls.Add(this.OpenFileButton);
			this.FigureGroupBox.Controls.Add(this.MyControl);
			this.FigureGroupBox.Controls.Add(this.ModifyButton);
			this.FigureGroupBox.Controls.Add(this.SaveButton);
			this.FigureGroupBox.Controls.Add(this.RandomObjectButton);
			this.FigureGroupBox.Controls.Add(this.FindObjectButton);
			this.FigureGroupBox.Controls.Add(this.FigureGrid);
			this.FigureGroupBox.Controls.Add(this.RemoveButton);
			this.FigureGroupBox.Controls.Add(this.AddButton);
			this.FigureGroupBox.Location = new System.Drawing.Point(12, 12);
			this.FigureGroupBox.Name = "FigureGroupBox";
			this.FigureGroupBox.Size = new System.Drawing.Size(707, 307);
			this.FigureGroupBox.TabIndex = 0;
			this.FigureGroupBox.TabStop = false;
			this.FigureGroupBox.Text = "Table of figures";
			// 
			// OpenFileButton
			// 
			this.OpenFileButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.OpenFileButton.Location = new System.Drawing.Point(143, 263);
			this.OpenFileButton.Name = "OpenFileButton";
			this.OpenFileButton.Size = new System.Drawing.Size(88, 33);
			this.OpenFileButton.TabIndex = 9;
			this.OpenFileButton.Text = "Open file";
			this.OpenFileButton.UseVisualStyleBackColor = true;
			this.OpenFileButton.Click += new System.EventHandler(this.OpenFileButton_Click);
			// 
			// MyControl
			// 
			this.MyControl.Location = new System.Drawing.Point(515, 20);
			this.MyControl.Name = "MyControl";
			this.MyControl.ReadOnly = true;
			this.MyControl.Size = new System.Drawing.Size(191, 112);
			this.MyControl.TabIndex = 8;
			// 
			// ModifyButton
			// 
			this.ModifyButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.ModifyButton.Location = new System.Drawing.Point(425, 263);
			this.ModifyButton.Name = "ModifyButton";
			this.ModifyButton.Size = new System.Drawing.Size(88, 33);
			this.ModifyButton.TabIndex = 7;
			this.ModifyButton.Text = "Modify objects";
			this.ModifyButton.UseVisualStyleBackColor = true;
			this.ModifyButton.Click += new System.EventHandler(this.ModifyButton_Click);
			// 
			// SaveButton
			// 
			this.SaveButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.SaveButton.Location = new System.Drawing.Point(237, 263);
			this.SaveButton.Name = "SaveButton";
			this.SaveButton.Size = new System.Drawing.Size(88, 33);
			this.SaveButton.TabIndex = 6;
			this.SaveButton.Text = "Save data";
			this.SaveButton.UseVisualStyleBackColor = true;
			this.SaveButton.Click += new System.EventHandler(this.SaveButton_Click);
			// 
			// RandomObjectButton
			// 
			this.RandomObjectButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.RandomObjectButton.Location = new System.Drawing.Point(9, 263);
			this.RandomObjectButton.Name = "RandomObjectButton";
			this.RandomObjectButton.Size = new System.Drawing.Size(88, 33);
			this.RandomObjectButton.TabIndex = 5;
			this.RandomObjectButton.Text = "Random";
			this.RandomObjectButton.UseVisualStyleBackColor = true;
			this.RandomObjectButton.Click += new System.EventHandler(this.RandomObjectButton_Click);
			// 
			// FindObjectButton
			// 
			this.FindObjectButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.FindObjectButton.Location = new System.Drawing.Point(331, 263);
			this.FindObjectButton.Name = "FindObjectButton";
			this.FindObjectButton.Size = new System.Drawing.Size(88, 33);
			this.FindObjectButton.TabIndex = 4;
			this.FindObjectButton.Text = "Find objects";
			this.FindObjectButton.UseVisualStyleBackColor = true;
			this.FindObjectButton.Click += new System.EventHandler(this.FindObjectButton_Click);
			// 
			// FigureGrid
			// 
			this.FigureGrid.AllowUserToAddRows = false;
			this.FigureGrid.AllowUserToDeleteRows = false;
			this.FigureGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.FigureGrid.GridColor = System.Drawing.Color.White;
			this.FigureGrid.Location = new System.Drawing.Point(7, 20);
			this.FigureGrid.Name = "FigureGrid";
			this.FigureGrid.ReadOnly = true;
			this.FigureGrid.Size = new System.Drawing.Size(502, 232);
			this.FigureGrid.TabIndex = 0;
			this.FigureGrid.SelectionChanged += new System.EventHandler(this.FigureGrid_SelectionChanged);
			// 
			// RemoveButton
			// 
			this.RemoveButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.RemoveButton.Location = new System.Drawing.Point(613, 263);
			this.RemoveButton.Name = "RemoveButton";
			this.RemoveButton.Size = new System.Drawing.Size(88, 33);
			this.RemoveButton.TabIndex = 2;
			this.RemoveButton.Text = "Remove object";
			this.RemoveButton.UseVisualStyleBackColor = true;
			this.RemoveButton.Click += new System.EventHandler(this.RemoveButton_Click);
			// 
			// AddButton
			// 
			this.AddButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.AddButton.Location = new System.Drawing.Point(519, 263);
			this.AddButton.Name = "AddButton";
			this.AddButton.Size = new System.Drawing.Size(88, 33);
			this.AddButton.TabIndex = 1;
			this.AddButton.Text = "Add object";
			this.AddButton.UseVisualStyleBackColor = true;
			this.AddButton.Click += new System.EventHandler(this.AddButton_Click);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(731, 331);
			this.Controls.Add(this.FigureGroupBox);
			this.MaximumSize = new System.Drawing.Size(747, 370);
			this.MinimumSize = new System.Drawing.Size(747, 370);
			this.Name = "MainForm";
			this.Text = "Main window";
			this.FigureGroupBox.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.FigureGrid)).EndInit();
			this.ResumeLayout(false);

		}

#endregion

		private System.Windows.Forms.GroupBox FigureGroupBox;
		private System.Windows.Forms.Button RemoveButton;
		private System.Windows.Forms.Button AddButton;
		private System.Windows.Forms.DataGridView FigureGrid;
		private System.Windows.Forms.Button FindObjectButton;
#if DEBUG
		private System.Windows.Forms.Button RandomObjectButton;
#endif
		private System.Windows.Forms.Button SaveButton;
		private System.Windows.Forms.Button ModifyButton;
		private ObjectControl MyControl;
		private System.Windows.Forms.Button OpenFileButton;
	}
}

