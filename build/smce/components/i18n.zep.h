
extern zend_class_entry *smce_components_i18n_ce;

ZEPHIR_INIT_CLASS(Smce_Components_I18n);

PHP_METHOD(Smce_Components_I18n, setDir);
PHP_METHOD(Smce_Components_I18n, setDirSearch);
PHP_METHOD(Smce_Components_I18n, setLangList);
PHP_METHOD(Smce_Components_I18n, setLang);
PHP_METHOD(Smce_Components_I18n, t);
PHP_METHOD(Smce_Components_I18n, search);
PHP_METHOD(Smce_Components_I18n, search_replace);
PHP_METHOD(Smce_Components_I18n, out);
PHP_METHOD(Smce_Components_I18n, in_replace);
PHP_METHOD(Smce_Components_I18n, uniqueArr);
PHP_METHOD(Smce_Components_I18n, addArr);
PHP_METHOD(Smce_Components_I18n, addArr2);
PHP_METHOD(Smce_Components_I18n, writeFile);
PHP_METHOD(Smce_Components_I18n, is);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_setdir, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_setdirsearch, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_setlanglist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, list, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_setlang, 0, 0, 1)
	ZEND_ARG_INFO(0, lang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_t, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_ARRAY_INFO(0, arr, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_out, 0, 0, 1)
	ZEND_ARG_INFO(0, arr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_uniquearr, 0, 0, 1)
	ZEND_ARG_INFO(0, arr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_addarr, 0, 0, 2)
	ZEND_ARG_INFO(0, arr)
	ZEND_ARG_INFO(0, arr2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_addarr2, 0, 0, 2)
	ZEND_ARG_INFO(0, arr)
	ZEND_ARG_INFO(0, arr2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_i18n_writefile, 0, 0, 2)
	ZEND_ARG_INFO(0, arr)
	ZEND_ARG_INFO(0, file_x)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_components_i18n_method_entry) {
	PHP_ME(Smce_Components_I18n, setDir, arginfo_smce_components_i18n_setdir, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_I18n, setDirSearch, arginfo_smce_components_i18n_setdirsearch, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_I18n, setLangList, arginfo_smce_components_i18n_setlanglist, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_I18n, setLang, arginfo_smce_components_i18n_setlang, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_I18n, t, arginfo_smce_components_i18n_t, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Components_I18n, search, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_I18n, search_replace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_I18n, out, arginfo_smce_components_i18n_out, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Components_I18n, in_replace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_I18n, uniqueArr, arginfo_smce_components_i18n_uniquearr, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Components_I18n, addArr, arginfo_smce_components_i18n_addarr, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Components_I18n, addArr2, arginfo_smce_components_i18n_addarr2, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Components_I18n, writeFile, arginfo_smce_components_i18n_writefile, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Components_I18n, is, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
  PHP_FE_END
};
