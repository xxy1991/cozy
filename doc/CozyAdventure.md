CozyAdventure - 冒险与编程
===============================


游戏资源仓库
===============================
https://git.oschina.net/zapline/cozy_res_adventure.git  
clone 到 bin\CozyAdventureContent


游戏设计与计划
===============================

    ~~* 表示基本已完成

1、View 展现层

    1.1 Sence 场景页面
        1.1.1   LoginScene              首页（登陆）
        1.1.2   RegistScene             注册页
        1.1.3   LoadingScene            加载过程页
        1.1.4   CampScene               个人首页（营地）
        1.1.5   AdventureScene          冒险页面
        1.1.6   FollowerManageScene      佣兵管理页面
        1.1.7   FollowerListScene       佣兵列表
        1.1.8   FollowerRecruitScene    招募页面（抽卡）
        1.1.9   BossFightScene          Boss战页面
        1.1.10  BigMapScene             冒险地图选择页
        1.1.11  BagScene                背包页
        1.1.12  FollowerDismissScene    佣兵解雇页
        1.1.13  FavoriteScene           图鉴页
        1.1.14  FightLineupScene        出战阵容调整页
        1.1.15  FriendScene             好友管理页
        1.1.16  RankingListScene        战斗力排行榜
        1.1.17  GiftScene               礼包领取页面

    1.2 Sprite 可视对象
        1.2.1   FollowerSprite          佣兵卡牌
        1.2.2   PropSprite              物品

    1.3 Fight 战斗过程
        1.3.1   FarmFightView           刷怪
        1.3.2   BossFightView           打boss
        1.3.3   VersusFightView         对战
        1.3.4   TeamFightView           组队副本

    1.4 Layer 层
        ~~1.4.1   BackgroundLayer       背景层
        1.4.2   LoginUiLayer            登录页基本UI层
        1.4.3   RegistUiLayer           注册页基本UI层

2、Game 游戏内容

    2.1 Model 实体类
        ~~2.1.1   Player                  玩家
        ~~2.1.2   Follower                佣兵卡牌
        ~~2.1.3   Prop                    道具
        ~~2.1.4   FollowerCollect         佣兵组
        ~~2.1.5   PropCollect             道具集
        ~~2.1.6   FramMap                 刷怪地
        ~~2.1.7   Package                 包（包含道具、金币、经验等）

    2.2 Logic 游戏逻辑
        2.2.1   UserLogic               注册和登陆
        2.2.2   FightLogic              战斗逻辑
            ~~2.2.2.1   NormalFight     常规1v1战斗
        ~~2.2.3 FollowerLogic           佣兵战斗力计算
        2.2.4   FollowerCollectLogic    佣兵组逻辑
        2.2.5   FollowerLevelLogic      佣兵升级逻辑
        2.2.6   FollowerStarLogic       佣兵升星逻辑
        2.2.7   RankingListLogic        排行榜逻辑
        2.2.8   FramMapLogic            刷怪逻辑

    2.3 Object 游戏对象
        2.3.1   PlayerObject            玩家对象
        2.3.2   BagObject               我的背包
    
    
3、Public 公共内容

    3.1 Controls 控件
        ~3.1.1  Button
        ~3.1.2  ListView

    3.2 Update 更新



数值设计
===============================

- 随从战斗力 = 基础战力 + (星级基础战力 + 星级战力成长 * 等级) * 成长细数
    - baseAttack = new List<int>() { 0, 300, 1000, 2500, 5000, 9000 };
    - growAttack = new List<int>() { 10, 20, 30, 50, 100, 150 };
    - 每个星级最多可以升级20级，对应满级战斗力为：200、700、1600、3500、7000、12000

- 随从个数跟关卡、战斗力要求、每分钟经验获取、每分钟金币获取的对应关系：
    <table><tbody>
    <tr>
        <td><em>随从个数</em></td>
        <td><em>关卡</em></td>
        <td><em>战斗力要求</em></td>
        <td><em>经验</em></td>
        <td><em>金币</em></td>
    </tr>
    <tr>
        <td>1</td>
        <td>1-5</td>
        <td>0-100</td>
        <td>1-10</td>
        <td>1-2</td>
    </tr>
    <tr>
        <td>2</td>
        <td>6-10</td>
        <td>200-800</td>
        <td>20-80</td>
        <td>3-10</td>
    </tr>
    <tr>
        <td>3</td>
        <td>11-20</td>
        <td>1000-1500</td>
        <td>100-150</td>
        <td>15-30</td>
    </tr>
    <tr>
        <td>4</td>
        <td>21-30</td>
        <td>2000-3000</td>
        <td>200-300</td>
        <td>35-50</td>
    </tr>
    <tr>
        <td>5</td>
        <td>31-50</td>
        <td>3500-8000</td>
        <td>350-800</td>
        <td>60-100</td>
    </tr>
    </tbody></table>

- 升级所需的经验：
    - 每个小时，各关卡层级获得经验和大概为：300、3000、7000、15000、30000
    - 每个小时，各关卡层级获得金币和大概为：50、300、1200、2500、5000
    - 升星要求经验和金币依次为：200-20、1000-100、5000-500
    - 0-2星级升级经验依次为：5-100、100-300、300-1000

- 卡牌星级与基本战斗力、成长细数对应情况
    - 普通 - 0 - 1-10     - 0.8-1.0
    - 优秀 - 1 - 1-20     - 1.0-1.2
    - 精英 - 2 - 10-50    - 1.0-1.3
    - 王者 - 3 - 30-100   - 1.1-1.4
    - 传奇 - 4 - 50-200   - 1.1-1.5
    - 史诗 - 5 - 100-500  - 1.2-1.6
    - 传说 - 6 - 200-1000 - 1.3-1.8

- 每个系列卡包有5-20张随从卡
- 第一阶段出4个卡包，包含普通×20、优秀×10、精英×5、王者×2
    - 路人包（10张）普通9、优秀1
        - 路人甲 优秀 5 - 1.1 
        - 路人乙丙丁戊己庚辛壬癸 普通 1 - 0.8
    - 三国蜀汉包（12张）优秀8、精英4
        - 庞统、法正、马良、姜维、马岱、马谡、黄忠、魏延 优秀 10 - 1.05
        - 张飞、关羽、赵云、诸葛亮 精英 30 - 1.1
    - 动物包（10张）普通8、优秀1、王者1
        - 鸡王 王者 50 - 1.1
        - 猪王 优秀 5 - 1.0
        - 马、牛、山羊、绵羊、猫、狗、鹰、狼 普通 2 - 0.85
    - 我的世界生物包（5张）普通3、精英1、王者1
        - 末影龙 王者 30 - 1.15
        - 苦力怕 精英 10 - 1.05
        - 小白、小黑、蜘蛛 普通 2 - 0.9