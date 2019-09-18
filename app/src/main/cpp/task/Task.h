//
// Created by Administrator on 2019/9/18.
//

#ifndef TASKOK_TASK_H
#define TASKOK_TASK_H

#include "job.h"
class ThreadPool;

class Task {
    friend  class ThreadPool;
private:
    job_t *job;
public:
    Task();

protected:
    virtual int onPreDo();
    virtual int onDo();
    virtual int onPostDo();
    virtual void onDestroy();
private:
    int process();
    void destroy();
    static void onJobPorcess(job_t* job);


};

class ThreadPool{
private:
    workqueue_t workQueue;

public:
    ThreadPool();
    void shutDown();
    void addTask(Task *task);
    void init(int numWorkers);

    int exit();

protected:
    worker_t *   queryWorker(int wid);
    void  onWorkInitFn(workqueue_t *wq, int wid);
    void  onWorkDestoryFn(workqueue_t *wq, int wid);
    void  onWorkThreadEnterFn(workqueue_t *wq, int wid);
    void  onWorkThreadExitFn(workqueue_t *wq, int wid);

private:
    static void  workInitFn(workqueue_t *wq, int wid);
    static void  workDestoryFn(workqueue_t *wq, int wid);

    static void  workThreadEnterFn(workqueue_t *wq, int wid);
    static void  workThreadExitFn(workqueue_t *wq, int wid);
};


#endif //TASKOK_TASK_H
