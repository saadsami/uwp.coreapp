// Include the precompiled headers
#include "pch.h"

using namespace Platform;

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;

ref class App sealed : public Windows::ApplicationModel::Core::IFrameworkView
{

public:
    // Inherited via IFrameworkView
    virtual void Initialize(Windows::ApplicationModel::Core::CoreApplicationView^ applicationView)
    {
    }

    virtual void SetWindow(Windows::UI::Core::CoreWindow^ window)
    {
        UNREFERENCED_PARAMETER(window);
    }

    virtual void Load(Platform::String^ entryPoint)
    {
        UNREFERENCED_PARAMETER(entryPoint);
    }

    virtual void Run()
    {
        Windows::UI::Core::CoreWindow^ window = CoreWindow::GetForCurrentThread();
        window->Activate();

        Windows::UI::Core::CoreDispatcher^ dispatcher = window->Dispatcher;
        dispatcher->ProcessEvents(Windows::UI::Core::CoreProcessEventsOption::ProcessUntilQuit);
    }

    virtual void Uninitialize()
    {
    }
};

ref class AppSource sealed : Windows::ApplicationModel::Core::IFrameworkViewSource
{
public:
    // Inherited via IFrameworkViewSource
    virtual Windows::ApplicationModel::Core::IFrameworkView^  CreateView()
    {
        return ref new App();
    }
};

int main(Platform::Array<Platform::String^>^ args)
{
    Windows::ApplicationModel::Core::CoreApplication::Run(ref new AppSource());
    return 0;
}
