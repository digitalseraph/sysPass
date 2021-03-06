<?php

/**
 * sysPass
 * 
 * @author nuxsmin
 * @link http://syspass.org
 * @copyright 2012-2015 Rubén Domínguez nuxsmin@syspass.org
 *  
 * This file is part of sysPass.
 *
 * sysPass is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * sysPass is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with sysPass.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

define('APP_ROOT', '..');
require_once APP_ROOT . DIRECTORY_SEPARATOR . 'inc' . DIRECTORY_SEPARATOR . 'init.php';

SP_Util::checkReferer('POST');

if (!SP_Init::isLoggedIn()) {
    SP_Common::printJSON(_('La sesión no se ha iniciado o ha caducado'), 10);
}

if (SP_Util::demoIsEnabled()) {
    SP_Common::printJSON(_('Ey, esto es una DEMO!!'));
}

$sk = SP_Common::parseParams('p', 'sk', false);

if (!$sk || !SP_Common::checkSessionKey($sk)) {
    SP_Common::printJSON(_('CONSULTA INVÁLIDA'));
}

$frmDBUser = SP_Common::parseParams('p', 'dbuser');
$frmDBPass = SP_Common::parseParams('p', 'dbpass');
$frmDBName = SP_Common::parseParams('p', 'dbname');
$frmDBHost = SP_Common::parseParams('p', 'dbhost');
$frmMigrateEnabled = SP_Common::parseParams('p', 'chkmigrate', 0, false, 1);

if (!$frmMigrateEnabled) {
    SP_Common::printJSON(_('Confirmar la importación de cuentas'));
}

if (!$frmDBUser) {
    SP_Common::printJSON(_('Es necesario un usuario de conexión'));
}

if (!$frmDBPass) {
    SP_Common::printJSON(_('Es necesaria una clave de conexión'));
}

if (!$frmDBName) {
    SP_Common::printJSON(_('Es necesario el nombre de la BBDD'));
}

if (!$frmDBHost) {
    SP_Common::printJSON(_('Es necesario un nombre de host'));
}

$options['dbhost'] = $frmDBHost;
$options['dbname'] = $frmDBName;
$options['dbuser'] = $frmDBUser;
$options['dbpass'] = $frmDBPass;

$res = SP_Migrate::migrate($options);

if (is_array($res['error'])) {
    foreach ($res['error'] as $error) {
        $errors [] = $error['description'];
        $errors [] = $error['hint'];
        error_log($error['hint']);
    }

    $out = implode('<br>', $errors);
    SP_Common::printJSON($out);
} else if (is_array($res['ok'])) {
    $out = implode('<br>', $res['ok']);

    SP_Common::printJSON($out, 0);
}