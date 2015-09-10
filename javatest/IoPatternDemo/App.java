package IoPatternDemo;

/**
 * 类与类之间的关系
 * 1 依赖 形参|局部变量
 * 2 关联 属性
 * 		 聚合 属性 整体与部分 不一致的生命周期
 * 		 组合 属性 整体与部分 一致的生命周期
 * 3 继承 父子类的关系
 * 4 实现 接口与实现类的关系
 * 
 * 装饰设计模式
 * @author JawieZhu
 *
 */
public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Voice v=new Voice();
		v.say();
		Amplifier am=new Amplifier(v);
		am.say();
	}

}
