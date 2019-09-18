package com.wenwp.taskok;

public class MessageReq<T> {
    private short type;
    private short typeu;
    private byte[] bodyData;
    private T cacheData;//需要 在缓存中保存的数据 如目前 消息需要将 clientId 和 taskId 形成 key-value的形式进行存储数据
    private RequestCallback requestCallback;
    public MessageReq(short type, short typeu, byte[] bodyData){
        this.type=type;
        this.typeu=typeu;
        this.bodyData=bodyData;
    }
    public MessageReq(short type, short typeu, byte[] bodyData, RequestCallback requestCallback){
        this.type=type;
        this.typeu=typeu;
        this.bodyData=bodyData;
        this.requestCallback=requestCallback;
    }

    public short getType() {
        return type;
    }

    public void setType(short type) {
        this.type = type;
    }

    public short getTypeu() {
        return typeu;
    }

    public void setTypeu(short typeu) {
        this.typeu = typeu;
    }

    public byte[] getBodyData() {
        return bodyData;
    }

    public void setBodyData(byte[] bodyData) {
        this.bodyData = bodyData;
    }

    public RequestCallback getRequestCallback() {
        return requestCallback;
    }

    public void setRequestCallback(RequestCallback requestCallback) {
        this.requestCallback = requestCallback;
    }

    public T getCacheData() {
        return cacheData;
    }

    public void setCacheData(T cacheData) {
        this.cacheData = cacheData;
    }
}
