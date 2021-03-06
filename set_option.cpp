#include "config.hpp"
#include "elona.hpp"
#include "variables.hpp"



namespace elona
{


void pc_turn(bool = true);


int submenu = 0;


void set_option()
{
    int cfg_sound2 = 0;
    int cfg_music2 = 0;
    int cfg_fullscreen2 = 0;
    int windoww2 = 0;
    int windowh2 = 0;
    int sel = 0;
    listmax = 0;
    page = 0;
    pagesize = 18;
    cs = 0;
    cc = 0;
    cs_bk = -1;
    page_bk = 0;
    cs_bk2 = 0;
    cfg_sound2 = cfg_sound;
    cfg_music2 = cfg_music;
    cfg_fullscreen2 = cfg_fullscreen;
    windoww2 = windoww;
    windowh2 = windowh;
    if (mode == 10)
    {
        sel = 2;
    }
    else
    {
        sel = 4;
    }
    gsel(sel);
    for (int cnt = 0; cnt < 8; ++cnt)
    {
        pos(cnt % 4 * 180, cnt / 4 * 300);
        picload(fs::u8path(u8"./graphic/g"s + (cnt + 1) + u8".bmp"), 1);
    }
    gsel(0);
    redraw(0);
    if (mode == 0)
    {
        screenupdate = -1;
        update_screen();
    }
    if (mode == 10)
    {
        gsel(4);
        gmode(0);
        pos(0, 0);
        picload(fs::u8path(u8"./graphic/title.bmp"), 1);
        gzoom(windoww, windowh, 4, 0, 0, 800, 600);
        gsel(0);
        gmode(0);
        pos(0, 0);
        gcopy(4, 0, 0, windoww, windowh);
        gmode(2);
    }
    if (submenu == 0)
    {
        if (jp)
        {
            q = u8"オプション"s;
            s(0) = u8"ゲームの設定"s;
            s(1) = u8"画面と音の設定"s;
            s(2) = u8"ネット機能の設定"s;
            s(3) = u8"詳細な設定"s;
            s(4) = u8"ゲームパッド"s;
            s(5) = u8"メッセージとログ"s;
            s(6) = u8"言語(Language)"s;
            s(7) = "";
        }
        if (en)
        {
            q = u8"Option"s;
            s(0) = u8"Game Setting"s;
            s(1) = u8"Screen & Sound"s;
            s(2) = u8"Network Setting"s;
            s(3) = u8"Detailed Setting"s;
            s(4) = u8"Game Pad"s;
            s(5) = u8"Message & Log"s;
            s(6) = u8"Language"s;
            s(7) = "";
        }
        dx = 370;
        dy = 270;
    }
    if (submenu == 1)
    {
        if (jp)
        {
            q = u8"ゲームの設定"s;
            s(0) = u8"ノルンの冒険ガイド"s;
            s(1) = u8"非好戦的NPCを無視"s;
            s(2) = u8"zキーの割当て"s;
            s(3) = u8"xキーの割当て"s;
            s(4) = u8"走り始める歩数"s;
            s(5) = u8"歩きの速さ"s;
            s(6) = u8"攻撃の間隔"s;
            s(7) = "";
        }
        if (en)
        {
            q = u8"Game Setting"s;
            s(0) = u8"Extra Help"s;
            s(1) = u8"Neutral Npcs"s;
            s(2) = u8"Assign z key"s;
            s(3) = u8"Assign x key"s;
            s(4) = u8"Start Running After"s;
            s(5) = u8"Walk Speed"s;
            s(6) = u8"Attack Interval"s;
            s(7) = "";
        }
        dx = 440;
        dy = 340;
    }
    if (submenu == 2)
    {
        if (jp)
        {
            q = u8"画面と音の設定"s;
            s(0) = u8"サウンドの再生*"s;
            s(1) = u8"midiの再生*"s;
            s(2) = u8"画面モード*"s;
            s(3) = u8"画面の大きさ*"s;
            s(4) = u8"スクロール"s;
            s(5) = u8"主人公中心に描写"s;
            s(6) = u8"心臓の音"s;
            s(7) = u8"攻撃時アニメ"s;
            s(8) = u8"天候エフェクト"s;
            s(9) = u8"光源の描写"s;
            s(10) = u8"アイテムの影描写"s;
            s(11) = "";
        }
        if (en)
        {
            q = u8"Screen & Sound"s;
            s(0) = u8"Sound*"s;
            s(1) = u8"Music*"s;
            s(2) = u8"Screen Mode*"s;
            s(3) = u8"Screen Resolution*"s;
            s(4) = u8"Smooth Scroll"s;
            s(5) = u8"Always Center"s;
            s(6) = u8"Heartbeat Sound"s;
            s(7) = u8"Attack Animation"s;
            s(8) = u8"Weather Effect"s;
            s(9) = u8"Lighting"s;
            s(10) = u8"object Shadow"s;
            s(11) = "";
        }
        dx = 440;
        dy = 370;
    }
    if (submenu == 3)
    {
        if (jp)
        {
            q = u8"ネット機能の設定"s;
            s(0) = u8"ネットの使用"s;
            s(1) = u8"定期的に接続"s;
            s(2) = u8"チャットをフィルタ"s;
            s(3) = "";
        }
        if (en)
        {
            q = u8"Network Setting"s;
            s(0) = u8"Use Network"s;
            s(1) = u8"Constantly Connect"s;
            s(2) = u8"Filter Chat"s;
            s(3) = "";
        }
        dx = 440;
        dy = 300;
    }
    if (submenu == 4)
    {
        if (jp)
        {
            q = u8"詳細な設定"s;
            s(0) = u8"走りの速さ"s;
            s(1) = u8"numlockを自動制御"s;
            s(2) = u8"タイトルの水の波紋"s;
            s(3) = u8"画面の更新頻度"s;
            s(4) = u8"走り時スクロール"s;
            s(5) = u8"オートターンの挙動"s;
            s(6) = u8"イベントの短縮"s;
            s(7) = "";
        }
        if (en)
        {
            q = u8"Detailed Setting"s;
            s(0) = u8"Run Speed"s;
            s(1) = u8"Auto Numlock"s;
            s(2) = u8"Title Water Effect"s;
            s(3) = u8"Screen Refresh"s;
            s(4) = u8"Scroll When Run"s;
            s(5) = u8"Auto Turn Speed"s;
            s(6) = u8"Skip Random Events"s;
            s(7) = "";
        }
        dx = 440;
        dy = 300;
    }
    if (submenu == 5)
    {
        if (jp)
        {
            q = u8"ゲームパッド"s;
            s(0) = u8"ゲームパッド"s;
            s(1) = u8"決定キー"s;
            s(2) = u8"キャンセルキー"s;
            s(3) = u8"所持品"s;
            s(4) = u8"行動"s;
            s(5) = u8"斜め移動(L)"s;
            s(6) = u8"拾う(R)"s;
            s(7) = u8"射撃(R)"s;
            s(8) = u8"目標(L)"s;
            s(9) = u8"ポーズメニュー"s;
            s(10) = u8"ヘルプ"s;
            s(11) = u8"キャラ情報"s;
            s(12) = u8"装填"s;
            s(13) = "";
        }
        if (en)
        {
            q = u8"Game Pad"s;
            s(0) = u8"Game Pad"s;
            s(1) = u8"Enter/Ok"s;
            s(2) = u8"Cancel"s;
            s(3) = u8"Inventory"s;
            s(4) = u8"Action"s;
            s(5) = u8"diagonal Move/(L)"s;
            s(6) = u8"Pick/(R)"s;
            s(7) = u8"Shoot/(R)"s;
            s(8) = u8"Target/(L)"s;
            s(9) = u8"Peuse/Menu"s;
            s(10) = u8"Help"s;
            s(11) = u8"Chara-sheet"s;
            s(12) = u8"Reload"s;
            s(13) = "";
        }
        dx = 440;
        dy = 430;
    }
    if (submenu == 6)
    {
        if (jp)
        {
            q = u8"メッセージとログ"s;
            s(0) = u8"ﾒｯｾｰｼﾞに分表示追加"s;
            s(1) = u8"過去のﾒｯｾｰｼﾞの透過"s;
            s(2) = "";
        }
        if (en)
        {
            q = u8"Message&Log"s;
            s(0) = u8"Add time info"s;
            s(1) = u8"Transparency"s;
            s(2) = "";
        }
        dx = 440;
        dy = 300;
    }
    if (submenu == 7)
    {
        if (jp)
        {
            q = u8"言語(Language)"s;
            s(0) = u8"言語*"s;
            s(1) = "";
        }
        if (en)
        {
            q = u8"Language"s;
            s(0) = u8"Language*"s;
            s(1) = "";
        }
        dx = 440;
        dy = 300;
    }
    for (int cnt = 0; cnt < 20; ++cnt)
    {
        if (s(cnt) == ""s)
        {
            break;
        }
        list(0, listmax) = cnt;
        listn(0, listmax) = s(cnt);
        ++listmax;
    }
    windowshadow = 1;

    bool reset_page = true;
    while (1)
    {
        if (reset_page)
        {
            if (cfg_zkey == 0)
            {
                key_quick = u8"z"s;
                key_zap = u8"Z"s;
            }
            else if (cfg_zkey == 1)
            {
                key_zap = u8"z"s;
                key_quick = u8"Z"s;
            }
            if (cfg_xkey == 0)
            {
                key_quickinv = u8"x"s;
                key_inventory = u8"X"s;
            }
            else if (cfg_xkey == 1)
            {
                key_inventory = u8"x"s;
                key_quickinv = u8"X"s;
            }
            redraw(0);
            cs_bk = -1;
            pagemax = (listmax - 1) / pagesize;
            if (page < 0)
            {
                page = pagemax;
            }
            else if (page > pagemax)
            {
                page = 0;
            }
            reset_page = false;
        }
        redraw(0);
        s(0) = q;
        s(1) = strhint3;
        pagesize = 0;
        if (mode == 1)
        {
            display_window(
                (windoww - dx) / 2 + inf_screenx, winposy(dy, 1), dx, dy);
        }
        else
        {
            display_window(
                (windoww - dx) / 2 + inf_screenx, winposy(dy) - 12, dx, dy);
        }
        pagesize = listmax;
        display_topic(lang(u8"項目"s, u8"Menu"s), wx + 34, wy + 36);
        if (mode == 10)
        {
            p = 2;
        }
        else
        {
            p = 4;
        }
        x = ww / 5 * 3;
        y = wh - 80;
        gmode(4, 180, 300, 50);
        pos(wx + ww / 3, wy + wh / 2);
        grotate(p, cmbg / 4 % 4 * 180, cmbg / 4 / 4 % 2 * 300, 0, x, y);
        gmode(2);
        keyrange = 0;
        for (int cnt = 0, cnt_end = (pagesize); cnt < cnt_end; ++cnt)
        {
            p = pagesize * page + cnt;
            if (p >= listmax)
            {
                break;
            }
            if (submenu == 0)
            {
                key_list(cnt) = key_select(cnt);
                ++keyrange;
                display_key(wx + 32, wy + 66 + cnt * 19 - 2, cnt);
            }
            else
            {
                key_list(cnt) = key_cancel;
                ++keyrange;
            }
        }
        if (submenu == 5)
        {
            p(0) = 0;
            p(1) = cnvjkey(key_enter);
            p(2) = cnvjkey(key_cancel);
            p(3) = cnvjkey(key_quickinv);
            p(4) = cnvjkey(key_quick);
            p(5) = cnvjkey(key_alter);
            p(6) = cnvjkey(key_get);
            p(7) = cnvjkey(key_fire);
            p(8) = cnvjkey(key_target);
            p(9) = cnvjkey(key_esc);
            p(10) = cnvjkey(key_help);
            p(11) = cnvjkey(key_charainfo);
            p(12) = cnvjkey(key_ammo);
            for (int cnt = 1; cnt < 20; ++cnt)
            {
                list(1, cnt) = p(cnt);
            }
        }
        font(lang(cfg_font1, cfg_font2), 14 - en * 2, 0);
        for (int cnt = 0, cnt_end = (pagesize); cnt < cnt_end; ++cnt)
        {
            p = pagesize * page + cnt;
            if (p >= listmax)
            {
                break;
            }
            i = list(0, p);
            s = listn(0, p);
            if (submenu == 0)
            {
                x = 8;
            }
            else
            {
                x = 0;
            }
            if (submenu == 3)
            {
                if (cfg_net == 0)
                {
                    if (cnt >= 1)
                    {
                        continue;
                    }
                }
            }
            cs_list(cs == cnt, s, wx + 56 + x, wy + 66 + cnt * 19 - 1, 0);
            if ((submenu != 5 || cnt <= 0) && submenu != 0)
            {
                pos(wx + 220, wy + 66 + cnt * 19 - 5);
                gcopy(3, 312, 336, 24, 24);
                pos(wx + 358, wy + 66 + cnt * 19 - 5);
                gcopy(3, 336, 336, 24, 24);
            }
            pos(wx + 250, wy + 66 + cnt * 19);
            if (submenu == 1)
            {
                if (cnt == 0)
                {
                    if (jp)
                    {
                        s(0) = u8"なし"s;
                        s(1) = u8"あり"s;
                    }
                    else
                    {
                        s(0) = u8"Don't show"s;
                        s(1) = u8"Show"s;
                    }
                    mes(s(cfg_extrahelp));
                }
                if (cnt == 1)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"Attack"s;
                        s(1) = u8"Ignore"s;
                    }
                    mes(s(cfg_ignoredislike));
                }
                if (cnt == 2)
                {
                    if (jp)
                    {
                        s(0) = u8"ｸｨｯｸﾒﾆｭｰ"s;
                        s(1) = u8"道具を振る"s;
                        s(2) = u8"割当なし"s;
                    }
                    else
                    {
                        s(0) = u8"Quick menu"s;
                        s(1) = u8"Zap"s;
                        s(2) = u8"Don't assign"s;
                    }
                    mes(s(cfg_zkey));
                }
                if (cnt == 3)
                {
                    if (jp)
                    {
                        s(0) = u8"ｸｲｯｸｲﾝﾍﾞﾝﾄﾘ"s;
                        s(1) = u8"道具を調べる"s;
                        s(2) = u8"割当なし"s;
                    }
                    else
                    {
                        s(0) = u8"Quick Inv"s;
                        s(1) = u8"Identify"s;
                        s(2) = u8"Don't assign"s;
                    }
                    mes(s(cfg_xkey));
                }
                if (cnt == 4)
                {
                    if (cfg_startrun >= 20)
                    {
                        if (jp)
                        {
                            mes(u8"走らない"s);
                        }
                        else
                        {
                            mes(u8"Dont't run"s);
                        }
                    }
                    else if (jp)
                    {
                        mes(""s + (cfg_startrun + 1) + u8"歩目から"s);
                    }
                    else
                    {
                        mes(u8"After "s + (cfg_startrun + 1) + u8" steps"s);
                    }
                }
                if (cnt == 5)
                {
                    mes(""s + cfg_walkwait + u8" wait"s);
                }
                if (cnt == 6)
                {
                    mes(""s + cfg_attackwait + u8" wait"s);
                }
            }
            if (submenu == 2)
            {
                if (cnt == 0)
                {
                    if (jp)
                    {
                        s(0) = u8"なし"s;
                        s(1) = u8"direct sound"s;
                        s(2) = u8"MCI"s;
                    }
                    else
                    {
                        s(0) = u8"None"s;
                        s(1) = u8"Direct sound"s;
                        s(2) = u8"MCI"s;
                    }
                    mes(s(cfg_sound2));
                }
                if (cnt == 1)
                {
                    if (jp)
                    {
                        s(0) = u8"なし"s;
                        s(1) = u8"direct music"s;
                        s(2) = u8"MCI"s;
                    }
                    else
                    {
                        s(0) = u8"None"s;
                        s(1) = u8"Direct music"s;
                        s(2) = u8"MCI"s;
                    }
                    mes(s(cfg_music2));
                }
                if (cnt == 2)
                {
                    if (jp)
                    {
                        s(0) = u8"ウィンドウ"s;
                        s(1) = u8"フルスクリーン"s;
                    }
                    else
                    {
                        s(0) = u8"Window mode"s;
                        s(1) = u8"Full screen"s;
                    }
                    mes(s(cfg_fullscreen2));
                }
                if (cnt == 3)
                {
                    mes(""s + windoww2 + u8" * "s + windowh2);
                }
                if (cnt == 4)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_scroll));
                }
                if (cnt == 5)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_alwayscenter));
                }
                if (cnt == 6)
                {
                    if (jp)
                    {
                        s(0) = u8"再生しない"s;
                        s(1) = u8"再生する"s;
                    }
                    else
                    {
                        s(0) = u8"Don't play"s;
                        s(1) = u8"Play"s;
                    }
                    mes(s(cfg_heart));
                }
                if (cnt == 7)
                {
                    if (jp)
                    {
                        s(0) = u8"アニメなし"s;
                        s(1) = u8"アニメあり"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_attackanime));
                }
                if (cnt == 8)
                {
                    if (jp)
                    {
                        s(0) = u8"アニメなし"s;
                        s(1) = u8"アニメあり"s;
                    }
                    else
                    {
                        s(0) = u8"No animation"s;
                        s(1) = u8"Always"s;
                    }
                    mes(s(cfg_env));
                }
                if (cnt == 9)
                {
                    if (jp)
                    {
                        s(0) = u8"高画質"s;
                        s(1) = u8"低画質"s;
                    }
                    else
                    {
                        s(0) = u8"High"s;
                        s(1) = u8"Low"s;
                    }
                    mes(s(cfg_shadow));
                }
                if (cnt == 10)
                {
                    if (jp)
                    {
                        s(0) = u8"なし（高速）"s;
                        s(1) = u8"あり（低速）"s;
                    }
                    else
                    {
                        s(0) = u8"No(Slow)"s;
                        s(1) = u8"Yes(Fast)"s;
                    }
                    mes(s(cfg_objectshadow));
                }
            }
            if (submenu == 3)
            {
                if (cnt == 0)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_net));
                }
                if (cnt == 1)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_netwish));
                }
                if (cnt == 2)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_netchat));
                }
            }
            if (submenu == 4)
            {
                if (cnt == 0)
                {
                    mes(""s + cfg_runwait + u8" wait"s);
                }
                if (cnt == 1)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_autonumlock));
                }
                if (cnt == 2)
                {
                    if (jp)
                    {
                        s(0) = u8"オフ(オンには出来ません)"s;
                        s(1) = u8"オフ(オンには出来ません)"s;
                    }
                    else
                    {
                        s(0) = u8"No(unsupported)"s;
                        s(1) = u8"No(unsupported)"s;
                    }
                    mes(s(0));
                }
                if (cnt == 3)
                {
                    if (jp)
                    {
                        s(0) = u8"オフ"s;
                        s(1) = u8"オン"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(""s + cfg_scrsync + u8" wait"s);
                }
                if (cnt == 4)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_runscroll));
                }
                if (cnt == 5)
                {
                    if (jp)
                    {
                        s(0) = u8"普通"s;
                        s(1) = u8"速め"s;
                        s(2) = u8"省略"s;
                    }
                    else
                    {
                        s(0) = u8"Normal"s;
                        s(1) = u8"High"s;
                        s(2) = u8"Highest"s;
                    }
                    mes(s(cfg_autoturn));
                }
                if (cnt == 6)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_skiprandevents));
                }
            }
            if (submenu == 5)
            {
                if (cnt == 0)
                {
                    if (jp)
                    {
                        s(0) = u8"使用しない"s;
                        s(1) = u8"使用する"s;
                    }
                    else
                    {
                        s(0) = u8"Don't use"s;
                        s(1) = u8"Use"s;
                    }
                    mes(s(cfg_joypad));
                }
                else if (list(1, cnt) == -1)
                {
                    mes(lang(u8"未設定"s, u8"Unassigned"s));
                }
                else
                {
                    mes(lang(u8"ボタン"s, u8"Button"s) + list(1, cnt));
                }
            }
            if (submenu == 6)
            {
                if (cnt == 0)
                {
                    if (jp)
                    {
                        s(0) = u8"しない"s;
                        s(1) = u8"する"s;
                    }
                    else
                    {
                        s(0) = u8"No"s;
                        s(1) = u8"Yes"s;
                    }
                    mes(s(cfg_msgaddtime));
                }
                if (cnt == 1)
                {
                    mes(""s + cfg_msgtrans * 10 + u8" %"s);
                }
            }
            if (submenu == 7)
            {
                if (cnt == 0)
                {
                    s(0) = u8"Japanese"s;
                    s(1) = u8"English"s;
                    mes(s(cfg_language));
                }
            }
        }
        if (submenu != 0)
        {
            if (submenu != 5)
            {
                pos(wx + 40, wy + wh - 70);
                font(lang(cfg_font1, cfg_font2), 12 + sizefix - en * 2, 0);
                if (jp)
                {
                    mes(u8"* 印のついた項目は、ゲームの再起動後に適用されます"s);
                }
                else
                {
                    mes(u8"Items marked with * require restart to apply changes."s);
                }
            }
        }
        if (submenu == 5)
        {
            pos(wx + 40, wy + wh - 110);
            font(lang(cfg_font1, cfg_font2), 12 + sizefix - en * 2, 0);
            if (jp)
            {
                mes(u8"ボタンを割り当てたい項目にカーソルをあわせて\nゲームパッドのボタンを押してください。(L),(R)の付いている\n項目は、メニュー画面でタブの移動に使われます。"s);
            }
            else
            {
                mes(u8"To assign a button, move the cursor to\nan item and press the button."s);
            }
        }
        if (keyrange != 0)
        {
            cs_bk = cs;
        }
        redraw(1);
        await(cfg_wait1);
        key_check();
        cursor_check();
        p = -1;
        for (int cnt = 0, cnt_end = (keyrange); cnt < cnt_end; ++cnt)
        {
            if (key == key_select(cnt))
            {
                p = list(0, pagesize * page + cnt);
                cs = cnt;
                break;
            }
        }
        if (p != -1)
        {
            if (submenu == 0)
            {
                submenu = p + 1;
                snd(20);
                set_option();
                return;
            }
        }
        if (submenu == 5)
        {
            if (cs > 0)
            {
                int j0 = 0;
                DIGETJOYSTATE(j0, 0);
                f = 0;
                for (int cnt = 0; cnt < 12; ++cnt)
                {
                    if (HMMBITCHECK(j0, 4 + cnt))
                    {
                        p = cnt;
                        for (int cnt = 0; cnt < 12; ++cnt)
                        {
                            jkey(cnt) = "";
                        }
                        list(1, cs) = p;
                        for (int cnt = 1; cnt < 20; ++cnt)
                        {
                            if (cs == cnt)
                            {
                                continue;
                            }
                            --list(1, cnt);
                            if (list(1, cnt) == p || list(1, cnt) <= -1)
                            {
                                list(1, cnt) = 12;
                            }
                        }
                        set_config(u8"enter", key_enter, list(1, 1));
                        set_config(u8"cancel", key_cancel, list(1, 2));
                        set_config(u8"quickinv", key_quickinv, list(1, 3));
                        set_config(u8"quick", key_quick, list(1, 4));
                        set_config(u8"alter", key_alter, list(1, 5));
                        set_config(u8"get", key_get, list(1, 6));
                        set_config(u8"fire", key_fire, list(1, 7));
                        set_config(u8"target", key_target, list(1, 8));
                        set_config(u8"esc", key_esc, list(1, 9));
                        set_config(u8"help", key_help, list(1, 10));
                        set_config(u8"charainfo", key_charainfo, list(1, 11));
                        set_config(u8"ammo", key_ammo, list(1, 12));
                        p(0) = 0;
                        p(1) = cnvjkey(key_enter);
                        p(2) = cnvjkey(key_cancel);
                        p(3) = cnvjkey(key_quickinv);
                        p(4) = cnvjkey(key_quick);
                        p(5) = cnvjkey(key_alter);
                        p(6) = cnvjkey(key_get);
                        p(7) = cnvjkey(key_fire);
                        p(8) = cnvjkey(key_target);
                        p(9) = cnvjkey(key_esc);
                        p(10) = cnvjkey(key_help);
                        p(11) = cnvjkey(key_charainfo);
                        p(12) = cnvjkey(key_ammo);
                        for (int cnt = 1; cnt < 20; ++cnt)
                        {
                            list(1, cnt) = p(cnt);
                        }
                        f = 1;
                        break;
                    }
                }
                if (f)
                {
                    snd(20);
                    await(200);
                    reset_page = true;
                    continue;
                }
            }
        }
        if (key == key_pageup || key == key_pagedown)
        {
            if (key == key_pageup)
            {
                p = 1;
            }
            else
            {
                p = -1;
            }
            if (submenu == 1)
            {
                if (cs == 0)
                {
                    cfg_extrahelp += p;
                    if (cfg_extrahelp > 1)
                    {
                        cfg_extrahelp = 1;
                    }
                    else if (cfg_extrahelp < 0)
                    {
                        cfg_extrahelp = 0;
                    }
                    snd(20);
                    set_config(u8"extraHelp", cfg_extrahelp);
                    reset_page = true;
                    continue;
                }
                if (cs == 1)
                {
                    cfg_ignoredislike += p;
                    if (cfg_ignoredislike > 1)
                    {
                        cfg_ignoredislike = 1;
                    }
                    else if (cfg_ignoredislike < 0)
                    {
                        cfg_ignoredislike = 0;
                    }
                    snd(20);
                    set_config(u8"ignoreDislike", cfg_ignoredislike);
                    reset_page = true;
                    continue;
                }
                if (cs == 2)
                {
                    cfg_zkey += p;
                    if (cfg_zkey > 2)
                    {
                        cfg_zkey = 2;
                    }
                    else if (cfg_zkey < 0)
                    {
                        cfg_zkey = 0;
                    }
                    snd(20);
                    set_config(u8"zkey", cfg_zkey);
                    reset_page = true;
                    continue;
                }
                if (cs == 3)
                {
                    cfg_xkey += p;
                    if (cfg_xkey > 2)
                    {
                        cfg_xkey = 2;
                    }
                    else if (cfg_xkey < 0)
                    {
                        cfg_xkey = 0;
                    }
                    snd(20);
                    set_config(u8"xkey", cfg_xkey);
                    reset_page = true;
                    continue;
                }
                if (cs == 4)
                {
                    cfg_startrun += p;
                    if (cfg_startrun > 20)
                    {
                        cfg_startrun = 20;
                    }
                    else if (cfg_startrun < 0)
                    {
                        cfg_startrun = 0;
                    }
                    snd(20);
                    set_config(u8"startRun", cfg_startrun);
                    reset_page = true;
                    continue;
                }
                if (cs == 5)
                {
                    cfg_walkwait += p;
                    if (cfg_walkwait > 10)
                    {
                        cfg_walkwait = 10;
                    }
                    else if (cfg_walkwait < 1)
                    {
                        cfg_walkwait = 1;
                    }
                    snd(20);
                    set_config(u8"walkWait", cfg_walkwait);
                    reset_page = true;
                    continue;
                }
                if (cs == 6)
                {
                    cfg_attackwait += p;
                    if (cfg_attackwait > 20)
                    {
                        cfg_attackwait = 20;
                    }
                    else if (cfg_attackwait < 1)
                    {
                        cfg_attackwait = 1;
                    }
                    snd(20);
                    set_config(u8"attackWait", cfg_attackwait);
                    reset_page = true;
                    continue;
                }
            }
            if (submenu == 2)
            {
                if (cs == 0)
                {
                    cfg_sound2 += p;
                    if (cfg_sound2 > 2)
                    {
                        cfg_sound2 = 2;
                    }
                    else if (cfg_sound2 < 0)
                    {
                        cfg_sound2 = 0;
                    }
                    snd(20);
                    set_config(u8"sound", cfg_sound2);
                    reset_page = true;
                    continue;
                }
                if (cs == 1)
                {
                    cfg_music2 += p;
                    if (cfg_music2 > 2)
                    {
                        cfg_music2 = 2;
                    }
                    else if (cfg_music2 < 0)
                    {
                        cfg_music2 = 0;
                    }
                    snd(20);
                    set_config(u8"music", cfg_music2);
                    reset_page = true;
                    continue;
                }
                if (cs == 2)
                {
                    cfg_fullscreen2 += p;
                    if (cfg_fullscreen2 > 1)
                    {
                        cfg_fullscreen2 = 1;
                    }
                    else if (cfg_fullscreen2 < 0)
                    {
                        cfg_fullscreen2 = 0;
                    }
                    snd(20);
                    set_config(u8"fullscreen", cfg_fullscreen2);
                    reset_page = true;
                    continue;
                }
                if (cs == 4)
                {
                    cfg_scroll += p;
                    if (cfg_scroll > 1)
                    {
                        cfg_scroll = 1;
                    }
                    else if (cfg_scroll < 0)
                    {
                        cfg_scroll = 0;
                    }
                    snd(20);
                    set_config(u8"scroll", cfg_scroll);
                    reset_page = true;
                    continue;
                }
                if (cs == 5)
                {
                    cfg_alwayscenter += p;
                    if (cfg_alwayscenter > 1)
                    {
                        cfg_alwayscenter = 1;
                    }
                    else if (cfg_alwayscenter < 0)
                    {
                        cfg_alwayscenter = 0;
                    }
                    snd(20);
                    set_config(u8"alwaysCenter", cfg_alwayscenter);
                    reset_page = true;
                    continue;
                }
                if (cs == 6)
                {
                    cfg_heart += p;
                    if (cfg_heart > 1)
                    {
                        cfg_heart = 1;
                    }
                    else if (cfg_heart < 0)
                    {
                        cfg_heart = 0;
                    }
                    snd(20);
                    set_config(u8"heartbeat", cfg_heart);
                    reset_page = true;
                    continue;
                }
                if (cs == 7)
                {
                    cfg_attackanime += p;
                    if (cfg_attackanime > 1)
                    {
                        cfg_attackanime = 1;
                    }
                    else if (cfg_attackanime < 0)
                    {
                        cfg_attackanime = 0;
                    }
                    snd(20);
                    set_config(u8"attackAnime", cfg_attackanime);
                    reset_page = true;
                    continue;
                }
                if (cs == 8)
                {
                    cfg_env += p;
                    if (cfg_env > 1)
                    {
                        cfg_env = 1;
                    }
                    else if (cfg_env < 0)
                    {
                        cfg_env = 0;
                    }
                    snd(20);
                    set_config(u8"envEffect", cfg_env);
                    reset_page = true;
                    continue;
                }
                if (cs == 9)
                {
                    cfg_shadow += p;
                    if (cfg_shadow > 1)
                    {
                        cfg_shadow = 1;
                    }
                    else if (cfg_shadow < 0)
                    {
                        cfg_shadow = 0;
                    }
                    snd(20);
                    set_config(u8"shadow", cfg_shadow);
                    reset_page = true;
                    continue;
                }
                if (cs == 10)
                {
                    cfg_objectshadow += p;
                    if (cfg_objectshadow > 1)
                    {
                        cfg_objectshadow = 1;
                    }
                    else if (cfg_objectshadow < 0)
                    {
                        cfg_objectshadow = 0;
                    }
                    snd(20);
                    set_config(u8"objectShadow", cfg_objectshadow);
                    reset_page = true;
                    continue;
                }
                if (cs == 3)
                {
                    x(0) = 800;
                    x(1) = 800;
                    x(2) = 1024;
                    x(3) = 1152;
                    x(4) = 1280;
                    x(5) = 1280;
                    y(0) = 600;
                    y(1) = 696;
                    y(2) = 768;
                    y(3) = 864;
                    y(4) = 768;
                    y(5) = 1024;
                    i = 0;
                    for (int cnt = 0; cnt < 5; ++cnt)
                    {
                        if (windoww2 == x(cnt))
                        {
                            if (windowh2 == y(cnt))
                            {
                                i = cnt;
                                break;
                            }
                        }
                    }
                    i += p;
                    if (i < 0)
                    {
                        i = 0;
                    }
                    else if (i > 4)
                    {
                        i = 4;
                    }
                    windoww2 = x(i);
                    windowh2 = y(i);
                    set_config(u8"windowW", windoww2);
                    set_config(u8"windowH", windowh2);
                    snd(20);
                    reset_page = true;
                    continue;
                }
            }
            if (submenu == 3)
            {
                if (cs == 0)
                {
                    cfg_net += p;
                    if (cfg_net > 1)
                    {
                        cfg_net = 1;
                    }
                    else if (cfg_net < 0)
                    {
                        cfg_net = 0;
                    }
                    snd(20);
                    set_config(u8"net", cfg_net);
                    reset_page = true;
                    continue;
                }
                if (cs == 1)
                {
                    cfg_netwish += p;
                    if (cfg_netwish > 1)
                    {
                        cfg_netwish = 1;
                    }
                    else if (cfg_netwish < 0)
                    {
                        cfg_netwish = 0;
                    }
                    snd(20);
                    set_config(u8"netWish", cfg_netwish);
                    reset_page = true;
                    continue;
                }
                if (cs == 2)
                {
                    cfg_netchat += p;
                    if (cfg_netchat > 1)
                    {
                        cfg_netchat = 1;
                    }
                    else if (cfg_netchat < 0)
                    {
                        cfg_netchat = 0;
                    }
                    snd(20);
                    set_config(u8"netChat", cfg_netchat);
                    reset_page = true;
                    continue;
                }
            }
            if (submenu == 4)
            {
                if (cs == 0)
                {
                    cfg_runwait += p;
                    if (cfg_runwait > 5)
                    {
                        cfg_runwait = 5;
                    }
                    else if (cfg_runwait < 2)
                    {
                        cfg_runwait = 2;
                    }
                    snd(20);
                    set_config(u8"runWait", cfg_runwait);
                    reset_page = true;
                    continue;
                }
                if (cs == 1)
                {
                    cfg_autonumlock += p;
                    if (cfg_autonumlock > 1)
                    {
                        cfg_autonumlock = 1;
                    }
                    else if (cfg_autonumlock < 0)
                    {
                        cfg_autonumlock = 0;
                    }
                    snd(20);
                    set_config(u8"autoNumlock", cfg_autonumlock);
                    reset_page = true;
                    continue;
                }
                if (cs == 2)
                {
                    snd(20);
                    set_config(u8"titleEffect", 0);
                    reset_page = true;
                    continue;
                }
                if (cs == 3)
                {
                    cfg_scrsync += p;
                    if (cfg_scrsync > 25)
                    {
                        cfg_scrsync = 25;
                    }
                    else if (cfg_scrsync < 2)
                    {
                        cfg_scrsync = 2;
                    }
                    snd(20);
                    set_config(u8"scr_sync", cfg_scrsync);
                    reset_page = true;
                    continue;
                }
                if (cs == 4)
                {
                    cfg_runscroll += p;
                    if (cfg_runscroll > 1)
                    {
                        cfg_runscroll = 1;
                    }
                    else if (cfg_runscroll < 0)
                    {
                        cfg_runscroll = 0;
                    }
                    snd(20);
                    set_config(u8"scroll_run", cfg_runscroll);
                    reset_page = true;
                    continue;
                }
                if (cs == 5)
                {
                    cfg_autoturn += p;
                    if (cfg_autoturn > 2)
                    {
                        cfg_autoturn = 2;
                    }
                    else if (cfg_autoturn < 0)
                    {
                        cfg_autoturn = 0;
                    }
                    snd(20);
                    set_config(u8"autoTurnType", cfg_autoturn);
                    reset_page = true;
                    continue;
                }
                if (cs == 6)
                {
                    cfg_skiprandevents += p;
                    if (cfg_skiprandevents > 1)
                    {
                        cfg_skiprandevents = 1;
                    }
                    else if (cfg_skiprandevents < 0)
                    {
                        cfg_skiprandevents = 0;
                    }
                    snd(20);
                    set_config(u8"skipRandEvents", cfg_skiprandevents);
                    reset_page = true;
                    continue;
                }
            }
            if (submenu == 5)
            {
                if (cs == 0)
                {
                    cfg_joypad += p;
                    if (cfg_joypad > 1)
                    {
                        cfg_joypad = 1;
                    }
                    else if (cfg_joypad < 0)
                    {
                        cfg_joypad = 0;
                    }
                    snd(20);
                    set_config(u8"joypad", cfg_joypad);
                    reset_page = true;
                    continue;
                }
            }
            if (submenu == 6)
            {
                if (cs == 0)
                {
                    cfg_msgaddtime += p;
                    if (cfg_msgaddtime > 1)
                    {
                        cfg_msgaddtime = 1;
                    }
                    else if (cfg_msgaddtime < 0)
                    {
                        cfg_msgaddtime = 0;
                    }
                    snd(20);
                    set_config(u8"msg_addTime", cfg_msgaddtime);
                    reset_page = true;
                    continue;
                }
                if (cs == 1)
                {
                    cfg_msgtrans += p;
                    if (cfg_msgtrans > 5)
                    {
                        cfg_msgtrans = 5;
                    }
                    else if (cfg_msgtrans < 0)
                    {
                        cfg_msgtrans = 0;
                    }
                    snd(20);
                    set_config(u8"msg_trans", cfg_msgtrans);
                    reset_page = true;
                    continue;
                }
            }
            if (submenu == 7)
            {
                if (cs == 0)
                {
                    cfg_language += p;
                    if (cfg_language > 1)
                    {
                        cfg_language = 1;
                    }
                    else if (cfg_language < 0)
                    {
                        cfg_language = 0;
                    }
                    snd(20);
                    set_config(u8"language", cfg_language);
                    reset_page = true;
                    continue;
                }
            }
        }
        if (key == key_cancel)
        {
            if (submenu != 0)
            {
                submenu = 0;
                set_option();
                return;
            }
            load_config();
            if (mode == 0)
            {
                if (cfg_net)
                {
                    initialize_server_info();
                }
                update_screen();
                pc_turn(false);
            }
            else
            {
                main_title_menu();
                return;
            }
        }
    }
}



} // namespace elona
