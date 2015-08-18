PHP_ARG_ENABLE(smce, whether to enable smce, [ --enable-smce   Enable Smce])

if test "$PHP_SMCE" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, SMCE_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_SMCE, 1, [Whether you have Smce])
	smce_sources="smce.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c smce/app.zep.c
	smce/components/collection.zep.c
	smce/components/i18n.zep.c
	smce/components/output.zep.c
	smce/components/session.zep.c
	smce/core/di.zep.c
	smce/core/di/diadapter.zep.c
	smce/core/di/dicache.zep.c
	smce/core/di/disingleton.zep.c
	smce/core/eventmanager.zep.c
	smce/core/loader.zep.c
	smce/core/queue.zep.c
	smce/core/queue/queueadapter.zep.c
	smce/core/queue/queuelisten.zep.c
	smce/core/queue/queuemodel.zep.c
	smce/core/smceframework.zep.c
	smce/driver/adapter.zep.c
	smce/driver/memcache.zep.c
	smce/driver/redis.zep.c
	smce/http/httpexception.zep.c
	smce/http/response.zep.c
	smce/mvc/acl.zep.c
	smce/mvc/layout.zep.c
	smce/mvc/router.zep.c
	smce/mvc/router/exception.zep.c
	smce/mvc/router/route.zep.c
	smce/mvc/template.zep.c
	smce/mvc/url.zep.c
	smce/sm.zep.c "
	PHP_NEW_EXTENSION(smce, $smce_sources, $ext_shared,, )
	PHP_SUBST(SMCE_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([smce], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([smce], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/smce], [php_SMCE.h])

fi
