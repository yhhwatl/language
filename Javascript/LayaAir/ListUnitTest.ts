/**
 * Created by hongyang on 16/4/20.
 */
/// <reference path="libs/LayaAir.d.ts" />
module ui
{
    import List=laya.ui.List;
    import Handler=laya.utils.Handler;
    // 实现List滚动方向的获取 实现获取当前选中的item
    // TODO 根据目前的API无法获取可见区域之外的Item 0.98版本
     export class ListSample 
     {
         private list:List = null;
         private num = 4;
        constructor()
        {
            Laya.init(550, 400);
            Laya.stage.scaleMode = laya.display.Stage.SCALE_SHOWALL;
            var list:List = new List();
            this.list = list;
            list.itemRender = Item;
            list.pos(90, 30);
            list.repeatX = 1;
            list.repeatY = this.num;
            // 使用但隐藏滚动条
            list.vScrollBarSkin = "";
            list.selectEnable = true;
            list.selectHandler = new Handler(this, this.onSelect);
            list.renderHandler = new Handler(this, this.updateItem);
            list.mouseHandler=new Handler(this, this.mouseItem);
            Laya.stage.addChild(list);
            // 设置数据项为对应图片的路径
            var data = [];
            for(var i:number = 0;i<15;i++)
            {
                data.push("res/ui/listskins/1.jpg");
            }

            list.array = data;
        }
        private lastIndex = 0;
        private lastScIndex = 0;
        private scrollXia = true;
        private selectIndex = -1;
        // private itemList : Array<Item> = [];
        private unSItem = null;
        private sItem = null;
        private updateItem(cell:Item, index:number):void 
        {
            console.log("updateItem:" + index);
            this.lastScIndex = index;
            if (this.lastScIndex > this.lastIndex) {
                this.scrollXia = false;
            }else{
                this.scrollXia = true;
            }
            // console.log("dir = ",this.scrollXia == true);
            this.lastIndex = this.lastScIndex;
            cell.setImg(cell.dataSource,index);
        }

        private  onSelect(index:number):void 
        {
            // if (this.selectIndex != -1) {
            //     var item = this.list.cells[this.selectIndex];
            //     if (item) {
            //         item.onUnSelected();
            //     }
            // }
            this.unSItem = this.sItem;
            if (this.unSItem) {
                this.unSItem.onUnSelected();
            }
            var showIndex = 0;
            // console.log("lastIndex = ",this.lastIndex);
            if (!this.scrollXia) {
                 showIndex = index - this.lastIndex + this.num;
            }else {
                showIndex = index - this.lastIndex;
            }
            
            var item = this.list.cells[showIndex];
            if (item) {
                item.onSelected();
                this.sItem = item;
                // console.log("seleItemIndex = ",item.)
            }
            this.selectIndex = showIndex;
            
            console.log("当前选择的索引：" + index);
        }
        private mouseItem(e:laya.events.Event,index:number):void {
            if(e.type== laya.events.Event.CLICK)
            {
                if(index==2)
                {
                    console.log("okla")
                }
            }
        }
    }
}
import Box=laya.ui.Box;
class Item extends Box 
{
    private txt:laya.ui.Label;
    private  img:laya.ui.Image;
    private index = 0;
    constructor()
    {
        super();
        this.size(373, 85);
        this.img = new laya.ui.Image();
        this.addChild(this.img);
        this.txt = new laya.ui.Label();
        this.txt.text = "index : 0";
        this.txt.color = "#FFFFFF";
        this.txt.fontSize = 35;
        this.img.addChild(this.txt);
        this.txt.pos(10,10);
    }
    
    public setImg(src:string,index:number):void 
    {
        this.img.skin = src;
        this.txt.text = "index : " + index;
        // this.index = index;
    }
    public onSelected() {
        console.log("item select " + this.index);
        this.txt.color = "#FF0000";
    }
    public onUnSelected() {
        console.log("item Unselect " + this.index);
        this.txt.color = "#FFFFFF";
    }
}
new ui.ListSample();