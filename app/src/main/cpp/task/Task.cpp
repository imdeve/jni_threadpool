//
// Created by Administrator on 2019/9/18.
//

#include <unistd.h>
#include <stdlib.h>
#include "Task.h"
#define  BZERO(buf,size)\
         memset(buf,0,size);

Task::Task(){
    this->job = (job_t*) malloc(sizeof(job_t));
    BZERO(this->job,sizeof(job_t));
    this->job->user_data = this;
    this->job->job_function = Task::onJobPorcess;
}
void Task::onJobPorcess(job_t *job) {
    Task * qthis = (Task*)job->user_data;
    qthis->process();
}
void Task::destroy() {
    this->onDestroy();
    //release
    if (this->job!=0)
    {
        free(this->job);
        this->job =0;
    }
}
void Task::onDestroy() {

}
int Task::onPreDo() {



return 0;

}

int Task::onDo() {

    return 0;
}

int Task::onPostDo() {

    return 0;
}

int Task::process() {
     this->onPreDo();
     this->onDo();
     this->onPostDo();
    return 0;
}

ThreadPool::ThreadPool() {
    BZERO(&this->workQueue, sizeof(workqueue_t));
    this->workQueue.userData = this;
}
void ThreadPool::init(int numWorkers) {
    this->workQueue.onWorkInitFn =  &workInitFn;
    this->workQueue.onWorkDestoryFn =  &workDestoryFn;
    this->workQueue.onWorkThreadEnter =  &onWorkThreadEnterFn;
    this->workQueue.onWorkThreadExit =  &onWorkThreadExitFn;

    threadpool_init(&this->workQueue,numWorkers);
}
void ThreadPool::addTask(Task *task) {
    workqueue_add_job(&this->workQueue,task->job);
}

void ThreadPool::workInitFn(workqueue_t *wq, int wid) {
    ThreadPool* tar = (ThreadPool*) wq->userData;
    tar->onWorkInitFn(wq,wid);
}

void ThreadPool::workDestoryFn(workqueue_t *wq, int wid) {
    ThreadPool* tar = (ThreadPool*) wq->userData;
    tar->onWorkDestoryFn(wq,wid);
}

void ThreadPool::workThreadEnterFn(workqueue_t *wq, int wid) {
    ThreadPool* tar = (ThreadPool*) wq->userData;
    tar->onWorkThreadEnterFn(wq,wid);
}


void ThreadPool::onWorkThreadEnterFn(workqueue_t *wq, int wid) {


}

void ThreadPool::workThreadExitFn(workqueue_t *wq, int wid) {
    ThreadPool* tar = (ThreadPool*) wq->userData;
    tar->onWorkThreadExitFn(wq,wid);
}

void ThreadPool::onWorkThreadExitFn(workqueue_t *wq, int wid) {

}

void ThreadPool::onWorkDestoryFn(workqueue_t *wq, int wid) {

}

void ThreadPool::onWorkInitFn(workqueue_t *wq, int wid) {


}
int ThreadPool::exit() {
    threadpool_exit(&this->workQueue);
    return 0;
}

worker_t* ThreadPool::queryWorker(int wid) {
    return threadpool_queryWorker(&this->workQueue,wid);
}