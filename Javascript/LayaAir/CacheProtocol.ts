/**
 * Cache protocol
 */
class  CacheProtocol{
    constructor(){
        
    }
    private static insatnce = null;
    public static getInstance():CacheProtocol {
        if (CacheProtocol.insatnce==null) {
            CacheProtocol.insatnce = new CacheProtocol();
        }
        return CacheProtocol.insatnce;
    }
    private sendList = [];
    private receiveList = [];
    public pushOperate(id,data) {
        console.log("push operate : ",id,data);
        if (this.sendList[id] == null) {
            this.sendList[id] = [];
        }
        this.sendList[id].push(data);
    }
    public refreshOpreate() {
        for (var id in this.sendList) {
            var ele = this.sendList[id];
            if (ele) {
                this.sendData(id,{id:id,times:ele.length});
            }
        }
        this.sendList = [];
    }
    public sendData(index,param) {
        console.log("send sendData : ",index,param);
        // 请求操作...
        var backData = true;
        var response = {index:index,param:param}
        if (backData) {
            this.receiveList.push(response);
        }
    }
    public receiveData() {
        for (var index in this.receiveList) {
            console.log("receive Data = ",this.receiveList[index]);
        }
        this.receiveList = [];
    }
     
}