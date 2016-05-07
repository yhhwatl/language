/**
 * protocolMain
 */
/// <reference path="../../libs/LayaAir.d.ts" />
/// <reference path="CacheProtocol.ts" />

class ProtocolMain {
    constructor() {
        Laya.init(550, 400);
        Laya.stage.scaleMode = laya.display.Stage.SCALE_SHOWALL;
        Laya.stage.bgColor = "#FF00FF";
        laya.utils.Stat.show(0, 0);
        this.initData();  
        this.initView();
        
    }
    private startTime = 0;
    private endTime = 0;
    private date = null;
    private initData() {
        this.date = new Date();
        this.startTime = this.date.getTime();
        console.log("startTime = ",this.startTime);        
    }
    private testLabel = null;
    private node = null;
    public initView() {
        var sName = ["采石场","伐木场","兽栏"];
        var touchTestSize = [];
        var touchLabel:Array<laya.ui.Label> = [];
        for (var index = 0; index < 3; index++) {
            var touchTest:laya.ui.Label = new laya.ui.Label();
            touchTest.text = sName[index];
            touchTest.fontSize = 30;
            touchTest.color = "#FFFFFF";
            
            Laya.stage.addChild(touchTest);
            touchTest.pos(index * 150,200);
            touchTestSize[index] = [];
            touchTestSize[index].w = touchTest.width;
            touchTestSize[index].h = touchTest.height;
            touchTest.on(laya.events.Event.CLICK,this,this.onTouch,[index,sName[index]]); 
        }
        
        var count = new laya.ui.Label();
        count.text = "223";
        count.fontSize = 25;
        this.testLabel = count;
        Laya.stage.addChild(count);
        count.pos(100,200);
        
        var spBtn1 = new laya.display.Sprite();
        spBtn1.size(200, 100);
        spBtn1.pos(127, 89);
        this.node = spBtn1;
        spBtn1.graphics.drawRect(0, 0, 200, 100, "#ff0000");
        Laya.stage.addChild(spBtn1);
        
        Laya.timer.loop(1000, this, this.updata);  
    }
    private isTouch = false;
    // 对齐方式 target根据type以12种方式与同父节点的node的四条边对齐
    private alignNode(target:laya.display.Sprite,node:laya.display.Sprite,type) {
        switch (type) {
            case 1:// 左上
                {
                   target.x = node.x;
                   target.y = node.y;
                   target.pivot(0,target.height); 
                }
                break;
            case 2:// 中上
                {
                   target.x = node.x + node.width/2;
                   target.y = node.y;
                   target.pivot(target.width/2,target.height); 
                }
                break;
            case 3:// 右上
                {
                   target.x = node.x + node.width;
                   target.y = node.y;
                   target.pivot(target.width,target.height); 
                }
                break;
            case 4:// 上右
                {
                   target.x = node.x + node.width;
                   target.y = node.y;
                   target.pivot(0,0); 
                }
                break;
            case 5:// 上中右
                {
                   target.x = node.x + node.width;
                   target.y = node.y + node.height/2;
                   target.pivot(0,target.height/2); 
                }
                break;   
            case 6:// 下右
                {
                   target.x = node.x + node.width;
                   target.y = node.y + node.height - target.height;
                   target.pivot(0,0); 
                }
                break;      
             case 7:// 右下
                {
                   target.x = node.x + node.width;
                   target.y = node.y + node.height;
                   target.pivot(target.width,0); 
                }
                break;
            case 8:// 中下
                {
                   target.x = node.x + node.width/2;
                   target.y = node.y + node.height;
                   target.pivot(target.width/2,0); 
                }
                break;
            case 9:// 左下
                {
                   target.x = node.x;
                   target.y = node.y + node.height;
                   target.pivot(0,0); 
                }
                break;
            case 10:// 上左
                {
                   target.x = node.x;
                   target.y = node.y + node.height;
                   target.pivot(target.width,target.height); 
                }
                break;   
            case 11:// 上中左
                {
                   target.x = node.x;
                   target.y = node.y + node.height/2 - target.height/2;
                   target.pivot(target.width,0); 
                }
                break;   
            case 12:// 下左
                {
                   target.x = node.x;
                   target.y = node.y;
                   target.pivot(target.width,0); 
                }
                break;   
            default:
                break;
        }
    }
    private onTouch(index,sName) {
        this.endTime = new Date().getTime();
        if (this.endTime - this.startTime < 1000) {
            console.log("连点")
            CacheProtocol.getInstance().pushOperate(index,{value:sName})
            this.isTouch = true;
        }else {
            // 单点 直接发送
        }
        this.startTime = this.endTime;
    }
    private touchTime =0;
    private updata() {
        if (this.isTouch) {
            this.endTime = new Date().getTime();
            if (this.endTime - this.startTime >= 1000) {
                console.log("没有连点")
                this.touchTime++;
                this.isTouch = false;
                this.testLabel.text = "我的";
                this.alignNode(this.testLabel,this.node,this.touchTime);
                CacheProtocol.getInstance().refreshOpreate();
            }
        }
        CacheProtocol.getInstance().receiveData();
    }
}