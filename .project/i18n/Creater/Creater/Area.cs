﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTY.Native.Tools.I18N.Creater
{
    internal enum LanguageArea
    {
        // Afrikaans (South Africa)
        af_ZA = 1078,
        // Albanian (Albania)
        sq_AL = 1052,
        // Amharic (Amhara)
        am_AM = 1118,
        // Arabic (Algeria)
        ar_DZ = 5121,
        // Arabic (Bahrain)
        ar_BH = 15361,
        // Arabic (Egypt)
        ar_EG = 3073,
        // Arabic (Iraq)
        ar_IQ = 2049,
        // Arabic (Jordan)
        ar_JO = 11265,
        // Arabic (Kuwait)
        ar_KW = 13313,
        // Arabic (Lebanon)
        ar_LB = 12289,
        // Arabic (Libya)
        ar_LY = 4097,
        // Arabic (Morocco)
        ar_MA = 6145,
        // Arabic (Oman)
        ar_OM = 8193,
        // Arabic (Qatar)
        ar_QA = 16385,
        // Arabic (Saudi Arabia)
        ar_SA = 1025,
        // Arabic (Syria)
        ar_SY = 10241,
        // Arabic (Tunisia)
        ar_TN = 7169,
        // Arabic (United Arab Emirates)
        ar_AE = 14337,
        // Arabic (Yemen)
        ar_YE = 9217,
        // Armenian (Armenian)
        hy_AM = 1067,
        // Assamese (Assamese)
        as_AS = 1101,
        // Azeri (Cyrillic)
        az_AZ_Cyrl = 2092,
        // Azeri (Latin)
        az_AZ_Latn = 2093,
        // Segoe UI (Basque)
        eu_ES = 1069,
        // Belarusian (Belarus)
        be_BY = 1059,
        // Bulgarian (Bulgaria)
        bg_BG = 1026,
        // Catalan (Catala)
        ca_ES = 1027,
        // Chinese (HongKong)
        zh_HK = 3076,
        // Chinese (Macau SAR)
        zh_MO = 5124,
        // Chinese (Simplified)
        zh_CN = 2052,
        // Chinese (Singapore)
        zh_SG = 4100,
        // Chinese (Taiwan)
        zh_TW = 1028,
        // Croatian (Croatia)
        hr_HR = 1050,
        // Czech (Czech)
        cd_CZ = 1029,
        // Danish (Denmark)
        da_DK = 1030,
        // Netherlands (Belgium)
        nl_BE = 2067,
        // Netherlands (Netherlands)
        nl_NL = 1043,
        // English (Australia)
        en_AU = 3081,
        // English (Belize)
        en_BZ = 10249,
        // English (Canada)
        en_CA = 4105,
        // English (Caribbean)
        en_CB = 9225,
        // English (Ireland)
        en_IE = 6153,
        // English (India)
        en_IN = 16393,
        // English (Jamaica)
        en_JM = 8201,
        // English (New Zealand)
        en_NZ = 5129,
        // English (Phillippines)
        en_PH = 13321,
        // English (Southern Africa)
        en_ZA = 7177,
        // English (Trinidad)
        en_TT = 11273,
        // English (Zimbabwe)
        en_ZW = 12297,
        // English (United States)
        en_US = 1033,
        // English (United Kingdom)
        en_UK = 2057,
        // Estonian (Estonia)
        et_EE = 1061,
        // Faroese (Faeroes)
        fo_FO = 1080,
        // Finnish (Finland)
        fi_FI = 1035,
        // French (Belgium)
        fr_BE = 2060,
        // French (Canada)
        fr_CA = 11276,
        // French (France)
        fr_FR = 1036,
        // French (Luxembourg)
        fr_LU = 5132,
        // French (Monaco)
        fr_MC = 6156,
        // French (Switzerland)
        fr_CH = 4108,
        // Galician (Galicia)
        gl_ES = 1110,
        // German (Austria)
        de_AT = 3079,
        // German (Germany)
        de_DE = 1031,
        // German (Liechtenstein)
        de_LI = 5127,
        // German (Luxembourg)
        de_LU = 4103,
        // German (Switzerland)
        de_CH = 2055,
        // Gujarati (India)
        gu_IN = 1095,
        // Hebrew (Israel)
        he_IL = 1037,
        // North Indian (India)
        hi_IN = 1081,
        // Hungarian (Hungary)
        hu_HU = 1038,
        // Icelandic (Iceland)
        is_IS = 1039,
        // Indonesian (Indonesia)
        id_ID = 1057,
        // Italian (Italy)
        it_IT = 1040,
        // Italian (Switzerland)
        it_CH = 2064,
        // Japanese (Japan)
        ja_JP = 1041,
        // Kannada (India)
        kn_IN = 1099,
        // Kazakh (Kazakhstan)
        kk_KZ = 1087,
        // Korean (Korea)
        ko_KR = 1042,
        // Kyrgyz (Kazakhstan)
        ky_KZ = 1088,
        // Latvian (Latvian)
        lv_LV = 1062,
        // Lithuanian (Lithuania)
        lt_LT = 1063,
        // Malay (Brunei)
        ms_BN = 2110,
        // Malay (Malaysia)
        ms_MY = 1086,
        // Marathi (India)
        mr_IN = 1102,
        // Mongolian (Mongolia)
        mn_MN = 2128,
        // Norwegian (Bokml)
        nb_NO = 1044,
        // Norwegian (Nynorsk)
        nn_NO = 2068,
        // Polish (Polish)
        pl_PL = 1045,
        // Portuguese (Brazil)
        pt_BR = 1046,
        // Portuguese (Portugal)
        pt_PT = 2070,
        // Punjab (India)
        pa_IN = 1094,
        // Romanian (Moldova)
        ro_MO = 2072,
        // Romanian (Romania)
        ro_RO = 1048,
        // Russian (Russia)
        ru_RU = 1049,
        // Russian (Moldova)
        ru_MO = 2073,
        // Sanskrit (India)
        sa_IN = 1103,
        // Serbia (Serre - Cyrillic)
        sr_SP_Cyrl = 3098,
        // Serbia (Serre - Latin)
        sr_SP_Latn = 2074,
        // Slovak (Slovak)
        sk_SK = 1051,
        // Slovenia (Slovenia)
        sl_SI = 1060,
        // Spanish (Argentina)
        es_AR = 11274,
        // Spanish (Bolivia)
        es_BO = 16394,
        // Spanish (Chile)
        es_CL = 13322,
        // Spanish (Colombia)
        es_CO = 9226,
        // Spanish (Costa Rica)
        es_CR = 5130,
        // Spanish (Dominican Republic)
        es_DO = 7178,
        // Spanish (Ecuador)
        es_EC = 12298,
        // Spanish (Salvador)
        es_SV = 17418,
        // Spanish (Guatemala)
        es_GT = 4106,
        // Spanish (Honduras)
        es_HN = 18442,
        // Spanish (Mexico)
        es_MX = 2058,
        // Spanish (Nicaragua)
        es_NI = 19466,
        // Spanish (Panama)
        es_PA = 6154,
        // Spanish (Paraguay)
        es_PY = 15370,
        // Spanish (Peru)
        es_PE = 10250,
        // Spanish (Puerto Rico)
        es_PR = 20490,
        // Spanish (Spain Traditional)
        es_ES = 1034,
        // Spanish (Uruguay)
        es_UY = 14346,
        // Spanish (Venezuela)
        es_VE = 8202,
        // Swahili (Kenya)
        sw_KE = 1089,
        // Swedish (Finland)
        sv_FI = 2077,
        // Swedish (Sweden)
        sv_SE = 1053,
        // Tamil (India)
        ta_IN = 1097,
        // Tatar (Russia)
        tt_RU = 1092,
        // Telugu (India)
        te_IN = 1098,
        // Thai (Thailand)
        th_TH = 1054,
        // Turkish (Turkey)
        tr_TR = 1055,
        // Uzbek (Uzbekistan - Cyrillics)
        uz_UZ_Cyrl = 2115,
        // Uzbek (Uzbekistan - Latin)
        uz_UZ_Latn = 1091,
        // Vietnamese (Vietnam)
        vi_VN = 1066,
    }

    internal class AreaHelper
    {
        public static string AreaString(LanguageArea area) => area switch
        {
            LanguageArea.en_UK => "en_UK",
            LanguageArea.en_US => "en_US",

            LanguageArea.zh_HK => "zh_HK",
            LanguageArea.zh_MO => "zh_MO",
            LanguageArea.zh_SG => "zh_SG",
            LanguageArea.zh_TW => "zh_TW",
            LanguageArea.zh_CN => "zh_CN",
            _ => "zh_CN"
        };

        public const string AreaKeyDefault = "default";
        public static string AreaKey(LanguageArea area) => area switch
        {
            LanguageArea.en_UK => "en",
            LanguageArea.en_US => "en",

            LanguageArea.zh_HK => "ch",
            LanguageArea.zh_MO => "ch",
            LanguageArea.zh_SG => "ch",
            LanguageArea.zh_TW => "ch",
            LanguageArea.zh_CN => "ch",
            _ => "ch"
        };

        public static LanguageArea ConvertAreaString(string value)
        {
            return value.ToLower() switch
            {
                "zh" or "zh_cn" => LanguageArea.zh_CN,
                "en" or "en_US" => LanguageArea.en_US,
                "en_UK" => LanguageArea.en_UK,
                _ => LanguageArea.zh_CN,
            };
        }
    }
}
