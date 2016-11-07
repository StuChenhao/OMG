// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 OMG_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// OMG_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef OMG_EXPORTS
#define OMG_API __declspec(dllexport)
#else
#define OMG_API __declspec(dllimport)
#endif
#include"OtherPlayer.h"
#include"SoursePlayer.h"
OMG_API int Add();

OMG_API bool playrole(SoursePlayer*p, OtherPlayer*op1, OtherPlayer*op2, OtherPlayer*op3,int*box);
OMG_API int selectplayer(SoursePlayer*p);

// 此类是从 OMG.dll 导出的
class OMG_API COMG {
public:
	COMG(void);
	// TODO:  在此添加您的方法。
};

extern OMG_API int nOMG;

OMG_API int fnOMG(void);
