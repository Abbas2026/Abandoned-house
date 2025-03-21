// SignalManager.h
#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include <QObject>

class SignalManager : public QObject {
    Q_OBJECT

public:
    static SignalManager* instance() {
        static SignalManager instance;
        return &instance;
    }

signals:
    void stopmusic();

private:
    SignalManager() {}
    ~SignalManager() {}
    SignalManager(const SignalManager&) = delete;
    SignalManager& operator=(const SignalManager&) = delete;
};

#endif // SIGNALMANAGER_H
