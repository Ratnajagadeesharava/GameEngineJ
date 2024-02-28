﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Editor.GameProject
{
    /// <summary>
    /// Interaction logic for ProjectBrowserDialog.xaml
    /// </summary>
    public partial class ProjectBrowserDialog : Window
    {
        public ProjectBrowserDialog()
        {
            InitializeComponent();
            openProejctButton.IsChecked = true;
        }

        private void ProejctButton_Click(object sender, RoutedEventArgs e)
        {
            if(sender == openProejctButton)
            {
                if(newProejctButton.IsChecked == true)
                {
                    newProejctButton.IsChecked = false;
                    libraryContentView.Margin = new Thickness(0);
                }
                openProejctButton.IsChecked = true;
                
            }
            else
            {
                if(openProejctButton.IsChecked == true)
                {
                    openProejctButton.IsChecked = false;
                    libraryContentView.Margin = new Thickness(-800, 0, 0, 0);
                }
                newProejctButton.IsChecked = true;
            }


        }

        
    }
}
