package com.wenwp.taskok;

public class MsgSenderMgr {

    private static MsgSenderMgr ins = new MsgSenderMgr();

    private MsgSenderMgr(){

    }
    static MsgSenderMgr getInstance()
    {
        return ins;
    }
    public void sendMsg(MessageReq message){

        message.getRequestCallback().success("from sdk data ");


    }






}
