#include "./EngineDefines.h"
#include "./CrashHandler.h"

namespace WEngine{

    class Event
    {
    public:
        int eventID;
        void *subscribers[__MAX_SUBSCRIBERS];
        void (*dispatchFunction[__MAX_SUBSCRIBERS])(void *self, void *infoBuff);

        void Clear(int newID)
        {
            for (int i = 0; i < __MAX_SUBSCRIBERS; i++)
            {
                subscribers[i] = nullptr;
                dispatchFunction[i] = nullptr;
            }
            eventID = newID;
        }
        void Add(void *self, void (*dispatchFunc)(void *self, void *infoBuff), CrashHandler *pCH)
        {
            for (int i = 0; i < __MAX_SUBSCRIBERS; i++)
            {
                if (subscribers[i] != nullptr)
                    continue;
                
                subscribers[i] = self;
                dispatchFunction[i] = dispatchFunc;
                return;
            }
            pCH->Crash("  Subscribe Failed!");
        }
    };

    class EventsManager
    {
    private:
        Event events[__MAX_EVENTS];
        CrashHandler *pCrashHandler;
    public:
        void Init(CrashHandler *pCH)
        {
            pCrashHandler = pCH;

            int count = 0;
            for (Event event : events)
            {
                event.Clear(count);
                count++;
            }
        }

        ///<summary>
        ///   This function subscribes a function to an 
        ///   event. A static function must be provided that
        ///   takes that pointer to itself and an infoBuffer,
        ///   that is provided at dispatch.
        ///</summary>
        template<class T>
        void Subscribe(int event, T *self, void (*dispatchFunc)(void *self, void *infoBuff))
        {
            events[event].Add((void*)self, dispatchFunc, pCrashHandler);
        }

        ///<summary>
        ///   This function calls every subscriber in
        ///   an event. The info buffer contains information
        ///   that should be dispatched to every subscriber.
        ///</summary>
        void Dispatch(int event, void *infoBuff)
        {
            for (int i = 0; i < __MAX_SUBSCRIBERS; i++)
            {
                if (events[event].dispatchFunction[i] == nullptr)
                    continue;
                events[event].dispatchFunction[i](events[event].subscribers[i], infoBuff);
            }
        }
    };  
}