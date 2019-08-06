namespace View
{
	partial class FindingForm
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
			this.components = new System.ComponentModel.Container();
			this.FindingGroupBox = new System.Windows.Forms.GroupBox();
			this.InputGroupBox = new System.Windows.Forms.GroupBox();
			this.SurfaceFirstTextBox = new System.Windows.Forms.TextBox();
			this.SearchButton = new System.Windows.Forms.Button();
			this.CircleCheckBox = new System.Windows.Forms.CheckBox();
			this.PerimeterSecondTextBox = new System.Windows.Forms.TextBox();
			this.RectangleCheckBox = new System.Windows.Forms.CheckBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.PerimeterFirstTextBox = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.SurfaceSecondTextBox = new System.Windows.Forms.TextBox();
			this.FigureGrid = new System.Windows.Forms.DataGridView();
			this.Figure = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.Surface = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.Perimeter = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.errorProvider = new System.Windows.Forms.ErrorProvider(this.components);
			this.FindingGroupBox.SuspendLayout();
			this.InputGroupBox.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.FigureGrid)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.errorProvider)).BeginInit();
			this.SuspendLayout();
			// 
			// FindingGroupBox
			// 
			this.FindingGroupBox.Controls.Add(this.InputGroupBox);
			this.FindingGroupBox.Controls.Add(this.FigureGrid);
			this.FindingGroupBox.Location = new System.Drawing.Point(12, 12);
			this.FindingGroupBox.Name = "FindingGroupBox";
			this.FindingGroupBox.Size = new System.Drawing.Size(398, 312);
			this.FindingGroupBox.TabIndex = 0;
			this.FindingGroupBox.TabStop = false;
			this.FindingGroupBox.Text = "Find objects";
			// 
			// InputGroupBox
			// 
			this.InputGroupBox.Controls.Add(this.SurfaceFirstTextBox);
			this.InputGroupBox.Controls.Add(this.SearchButton);
			this.InputGroupBox.Controls.Add(this.CircleCheckBox);
			this.InputGroupBox.Controls.Add(this.PerimeterSecondTextBox);
			this.InputGroupBox.Controls.Add(this.RectangleCheckBox);
			this.InputGroupBox.Controls.Add(this.label1);
			this.InputGroupBox.Controls.Add(this.label4);
			this.InputGroupBox.Controls.Add(this.label2);
			this.InputGroupBox.Controls.Add(this.PerimeterFirstTextBox);
			this.InputGroupBox.Controls.Add(this.label3);
			this.InputGroupBox.Controls.Add(this.SurfaceSecondTextBox);
			this.InputGroupBox.Location = new System.Drawing.Point(23, 19);
			this.InputGroupBox.Name = "InputGroupBox";
			this.InputGroupBox.Size = new System.Drawing.Size(350, 104);
			this.InputGroupBox.TabIndex = 14;
			this.InputGroupBox.TabStop = false;
			this.InputGroupBox.Text = "Input data";
			// 
			// SurfaceFirstTextBox
			// 
			this.SurfaceFirstTextBox.Location = new System.Drawing.Point(160, 17);
			this.SurfaceFirstTextBox.MaxLength = 7;
			this.SurfaceFirstTextBox.Name = "SurfaceFirstTextBox";
			this.SurfaceFirstTextBox.Size = new System.Drawing.Size(62, 20);
			this.SurfaceFirstTextBox.TabIndex = 8;
			this.SurfaceFirstTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.SurfaceFirstTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.SurfaceFirstTextBox_KeyPress);
			this.SurfaceFirstTextBox.Validating += new System.ComponentModel.CancelEventHandler(this.SurfaceFirstTextBox_Validating);
			// 
			// SearchButton
			// 
			this.SearchButton.Location = new System.Drawing.Point(6, 75);
			this.SearchButton.Name = "SearchButton";
			this.SearchButton.Size = new System.Drawing.Size(335, 23);
			this.SearchButton.TabIndex = 3;
			this.SearchButton.Text = "Search";
			this.SearchButton.UseVisualStyleBackColor = true;
			this.SearchButton.Click += new System.EventHandler(this.SearchButton_Click);
			// 
			// CircleCheckBox
			// 
			this.CircleCheckBox.AutoSize = true;
			this.CircleCheckBox.Location = new System.Drawing.Point(6, 46);
			this.CircleCheckBox.Name = "CircleCheckBox";
			this.CircleCheckBox.Size = new System.Drawing.Size(57, 17);
			this.CircleCheckBox.TabIndex = 5;
			this.CircleCheckBox.Text = "Circles";
			this.CircleCheckBox.UseVisualStyleBackColor = true;
			// 
			// PerimeterSecondTextBox
			// 
			this.PerimeterSecondTextBox.Location = new System.Drawing.Point(266, 46);
			this.PerimeterSecondTextBox.MaxLength = 7;
			this.PerimeterSecondTextBox.Name = "PerimeterSecondTextBox";
			this.PerimeterSecondTextBox.Size = new System.Drawing.Size(62, 20);
			this.PerimeterSecondTextBox.TabIndex = 13;
			this.PerimeterSecondTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.PerimeterSecondTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.SurfaceFirstTextBox_KeyPress);
			this.PerimeterSecondTextBox.Validating += new System.ComponentModel.CancelEventHandler(this.PerimeterFirstTextBox_Validating);
			// 
			// RectangleCheckBox
			// 
			this.RectangleCheckBox.AutoSize = true;
			this.RectangleCheckBox.Location = new System.Drawing.Point(6, 19);
			this.RectangleCheckBox.Name = "RectangleCheckBox";
			this.RectangleCheckBox.Size = new System.Drawing.Size(80, 17);
			this.RectangleCheckBox.TabIndex = 4;
			this.RectangleCheckBox.Text = "Rectangles";
			this.RectangleCheckBox.UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(99, 20);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(47, 13);
			this.label1.TabIndex = 6;
			this.label1.Text = "Surface:";
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(238, 49);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(16, 13);
			this.label4.TabIndex = 12;
			this.label4.Text = "to";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(99, 49);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(54, 13);
			this.label2.TabIndex = 7;
			this.label2.Text = "Perimeter:";
			// 
			// PerimeterFirstTextBox
			// 
			this.PerimeterFirstTextBox.Location = new System.Drawing.Point(160, 46);
			this.PerimeterFirstTextBox.MaxLength = 7;
			this.PerimeterFirstTextBox.Name = "PerimeterFirstTextBox";
			this.PerimeterFirstTextBox.Size = new System.Drawing.Size(62, 20);
			this.PerimeterFirstTextBox.TabIndex = 11;
			this.PerimeterFirstTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.PerimeterFirstTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.SurfaceFirstTextBox_KeyPress);
			this.PerimeterFirstTextBox.Validating += new System.ComponentModel.CancelEventHandler(this.PerimeterFirstTextBox_Validating);
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(238, 20);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(16, 13);
			this.label3.TabIndex = 9;
			this.label3.Text = "to";
			// 
			// SurfaceSecondTextBox
			// 
			this.SurfaceSecondTextBox.Location = new System.Drawing.Point(266, 17);
			this.SurfaceSecondTextBox.MaxLength = 7;
			this.SurfaceSecondTextBox.Name = "SurfaceSecondTextBox";
			this.SurfaceSecondTextBox.Size = new System.Drawing.Size(62, 20);
			this.SurfaceSecondTextBox.TabIndex = 10;
			this.SurfaceSecondTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.SurfaceSecondTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.SurfaceFirstTextBox_KeyPress);
			this.SurfaceSecondTextBox.Validating += new System.ComponentModel.CancelEventHandler(this.SurfaceFirstTextBox_Validating);
			// 
			// FigureGrid
			// 
			this.FigureGrid.AllowUserToAddRows = false;
			this.FigureGrid.AllowUserToDeleteRows = false;
			this.FigureGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.FigureGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Figure,
            this.Surface,
            this.Perimeter});
			this.FigureGrid.GridColor = System.Drawing.Color.White;
			this.FigureGrid.Location = new System.Drawing.Point(6, 129);
			this.FigureGrid.Name = "FigureGrid";
			this.FigureGrid.ReadOnly = true;
			this.FigureGrid.Size = new System.Drawing.Size(384, 172);
			this.FigureGrid.TabIndex = 1;
			// 
			// Figure
			// 
			this.Figure.HeaderText = "Figure";
			this.Figure.Name = "Figure";
			this.Figure.ReadOnly = true;
			this.Figure.Width = 75;
			// 
			// Surface
			// 
			this.Surface.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.Surface.HeaderText = "Surface";
			this.Surface.Name = "Surface";
			this.Surface.ReadOnly = true;
			// 
			// Perimeter
			// 
			this.Perimeter.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
			this.Perimeter.HeaderText = "Perimeter";
			this.Perimeter.Name = "Perimeter";
			this.Perimeter.ReadOnly = true;
			// 
			// errorProvider
			// 
			this.errorProvider.ContainerControl = this;
			// 
			// FindingForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(417, 331);
			this.Controls.Add(this.FindingGroupBox);
			this.MaximumSize = new System.Drawing.Size(433, 370);
			this.MinimumSize = new System.Drawing.Size(433, 370);
			this.Name = "FindingForm";
			this.Text = "FindingForm";
			this.FindingGroupBox.ResumeLayout(false);
			this.InputGroupBox.ResumeLayout(false);
			this.InputGroupBox.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.FigureGrid)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.errorProvider)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.GroupBox FindingGroupBox;
		private System.Windows.Forms.DataGridView FigureGrid;
		private System.Windows.Forms.DataGridViewTextBoxColumn Figure;
		private System.Windows.Forms.DataGridViewTextBoxColumn Surface;
		private System.Windows.Forms.DataGridViewTextBoxColumn Perimeter;
		private System.Windows.Forms.Button SearchButton;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.CheckBox CircleCheckBox;
		private System.Windows.Forms.CheckBox RectangleCheckBox;
		private System.Windows.Forms.GroupBox InputGroupBox;
		private System.Windows.Forms.TextBox SurfaceFirstTextBox;
		private System.Windows.Forms.TextBox PerimeterSecondTextBox;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox PerimeterFirstTextBox;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox SurfaceSecondTextBox;
		private System.Windows.Forms.ErrorProvider errorProvider;
	}
}