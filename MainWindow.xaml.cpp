#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::App1::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}


void winrt::App1::implementation::MainWindow::toggleOpen_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (toggleOpen().IsOn()) {
        Hello().ZoomMode(ZoomMode::Disabled);
        Hello().ZoomToFactor(1);
        ZoomSlider().Value(1);
        ZoomSlider().IsEnabled(FALSE);
    }
    else{
        Hello().ZoomMode(ZoomMode::Enabled);
        ZoomSlider().IsEnabled(TRUE);
    }
}

void winrt::App1::implementation::MainWindow::ZoomSlider_ValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e)
{
    mySize = e.NewValue();
    Hello().ZoomToFactor(mySize);
}
