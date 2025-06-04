package main

import "fmt"

type DemoA struct {
	name string
	id  int
}
type DemoB struct {
	age int
	sex string
}

type DemoC struct {
	DemoA
	DemoB
	score int
}


func main05() {
	var s DemoC=DemoC{DemoA{"戈洛文",7},DemoB{17,"男"},6}
	//s.name="戈洛文"
	//s.score=6
	//s.age=17
	//s.id=7
	//s.sex="男"
	//
	fmt.Println(s)
}
/*
type skills struct{
	名称
	耗蓝
	CD 冷却时间
	范围
	伤害
}
定义结构体切片 保存技能信息

type role struct{

	名称
	等级 lv
	经验 exp
	钻石
	金币
	生命值 hp
	攻击力
	暴击
	防御
	蓝量mp
	skills//匿名字段
	s []skills //结构体切片
}
*/

/*
type 信用卡 struct{
	卡号
	持卡人姓名
	额度
	有效期
	密码
	银行信息
	消费记录//匿名函数
	记录 []消费记录
}

type 消费记录 struct{
	卡号
	消费时间
	消费id
	流水号
	消费金额
	备注
}
 */
