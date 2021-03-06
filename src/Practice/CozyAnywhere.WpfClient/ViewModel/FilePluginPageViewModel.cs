﻿using CozyAnywhere.ClientCore;
using CozyAnywhere.WpfClient.Command;
using System;
using System.Collections.ObjectModel;
using System.Windows.Input;

namespace CozyAnywhere.WpfClient.ViewModel
{
    public class FilePluginPageViewModel : BaseViewModel
    {
        public AnywhereClient clientCore { get; set; }

        private ObservableCollection<Tuple<string, bool>> _FileList = new ObservableCollection<Tuple<string, bool>>();

        public ObservableCollection<Tuple<string, bool>> FileList
        {
            get
            {
                return _FileList;
            }
            set
            {
                Set(ref _FileList, value, "FileList");
            }
        }

        private Tuple<string, bool> _FileListSelectedItem;

        public Tuple<string, bool> FileListSelectedItem
        {
            get
            {
                return _FileListSelectedItem;
            }
            set
            {
                Set(ref _FileListSelectedItem, value, "FileListSelectedItem");
            }
        }

        private string _CurrentPath;
        public string CurrentPath
        {
            get
            {
                return _CurrentPath;
            }
            set
            {
                Set(ref _CurrentPath, value, "CurrentPath");
            }
        }

        private ICommand _DeleteCommand;

        public ICommand DeleteCommand
        {
            get
            {
                return _DeleteCommand = _DeleteCommand ?? new DelegateCommand((x) =>
                {
                    if (FileListSelectedItem != null)
                    {
                        clientCore.SendFileDeleteMessage(FileListSelectedItem.Item1);
                    }
                });
            }
        }

        private ICommand _RefreshCommand;
        public ICommand RefreshCommand
        {
            get
            {
                return _RefreshCommand = _RefreshCommand ?? new DelegateCommand((x) =>
                {
                    clientCore.SendFileEnumMessage(CurrentPath);
                });
            }
        }

        public FilePluginPageViewModel()
        {
            clientCore = MainWindowViewModel.clientCore;
            BindCoreCollections();

            clientCore.CurrentFilePathHandler += OnCurrentPathRefresh;
            clientCore.SendFileGetCurrentDirectoryMessage();
        }

        private void OnCurrentPathRefresh(object sender, ClientCore.EventArg.CurrentFilePathRefreshEventArgs e)
        {
            CurrentPath = e.Path;
        }

        private void BindCoreCollections()
        {
            if (clientCore != null)
            {
                clientCore.FileCollection = FileList;
            }
        }
    }
}