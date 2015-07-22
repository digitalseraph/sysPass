<div id="title" class="midroundup <?php echo $title['class']; ?>">
    <?php echo $title['name']; ?>
    <?php if ($gotData && $accountIsHistory): ?>
        <i id="history-icon" class="material-icons" title="<?php echo _('Histórico'); ?>"><?php echo $title['icon']; ?></i>
    <?php else: ?>
        <i id="history-icon" class="material-icons"><?php echo $title['icon']; ?></i>
    <?php endif; ?>
</div>

<?php if ($showform): ?>
<form method="post" name="frmaccount" id="frmAccount" onsubmit="saveAccount('frmAccount'); return false;">
    <?php endif; ?>
        <table class="data round">
            <tr>
                <td class="descField"><?php echo _('Nombre'); ?></td>
                <td class="valField">
                    <?php if ($showform): ?>
                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                            <input id="name" name="name" type="text" required class="mdl-textfield__input fg-blue100"
                            maxlength="50" value="<?php echo ($gotData) ? $accountData->account_name : ''; ?>">
                            <label class="mdl-textfield__label" for="name"><?php echo _('Nombre de cuenta'); ?></label>
                        </div>
                    <?php else: ?>
                        <?php echo $accountData->account_name; ?>
                    <?php endif; ?>
                </td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('Cliente'); ?></td>
                <td class="valField">
                    <?php if ($showform): ?>
                        <select id="selCustomer" name="customerId" class="select-box" required>
                            <option value="0"></option>
                            <?php foreach ($customers as $id => $name): ?>
                                <option
                                    value="<?php echo $id; ?>" <?php echo ($gotData && $id == $accountData->account_customerId) ? 'selected' : ''; ?>><?php echo $name; ?></option>
                            <?php endforeach; ?>
                        </select>
                        <br><br>
                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                            <input id="customer_new" name="customer_new" type="text" class="mdl-textfield__input fg-blue100" maxlength="50">
                            <label class="mdl-textfield__label" for="name"><?php echo _('Seleccionar o escribir para crear uno nuevo'); ?></label>
                        </div>
                    <?php else: ?>
                        <?php echo $accountData->customer_name; ?>
                    <?php endif; ?>
                </td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('Categoría'); ?></td>
                <td class="valField">
                    <?php if ($showform): ?>
                        <select id="selCategory" name="categoryId" class="select-box" required>
                            <option value="0"></option>
                            <?php foreach ($categories as $id => $name): ?>
                                <option
                                    value="<?php echo $id; ?>" <?php echo ($gotData && $id == $accountData->account_categoryId) ? 'selected' : ''; ?>><?php echo $name; ?></option>
                            <?php endforeach; ?>
                        </select>
                    <?php else: ?>
                        <?php echo $accountData->category_name; ?>
                    <?php endif; ?>
                </td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('URL / IP'); ?></td>
                <td class="valField">
                    <?php if ($showform): ?>
                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                            <input id="url" name="url" type="text" class="mdl-textfield__input fg-blue100"
                            maxlength="255" value="<?php echo ($gotData) ? $accountData->account_url : ''; ?>">
                            <label class="mdl-textfield__label" for="name"><?php echo _('URL o IP de acceso'); ?></label>
                        </div>
                    <?php else: ?>
                        <?php echo $accountData->account_url; ?>
                    <?php endif; ?>
                </td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('Usuario'); ?></td>
                <td class="valField">
                    <?php if ($showform): ?>
                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                            <input id="login" name="login" type="text" required class="mdl-textfield__input fg-blue100"
                            maxlength="50" value="<?php echo ($gotData) ? $accountData->account_login : ''; ?>">
                            <label class="mdl-textfield__label" for="name"><?php echo _('Usuario de acceso'); ?></label>
                        </div>
                    <?php else: ?>
                        <?php echo $accountData->account_login; ?>
                    <?php endif; ?>
                </td>
            </tr>
            <?php if ($showPass): ?>
                <tr>
                    <td class="descField"><?php echo _('Clave'); ?></td>
                    <td class="valField">
                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                            <input id="password" name="password" type="password" required class="mdl-textfield__input" maxlength="255"
                            OnKeyUp="checkPassLevel(this.value)" autocomplete="off">
                            <label class="mdl-textfield__label" for="password"><?php echo _('Clave'); ?></label>
                        </div>

                    <i class="showpass material-icons" title="<?php echo _('Mostrar Clave'); ?>">remove_red_eye</i>
                    <i id="passGen" class="material-icons" title="<?php echo _('Generar clave aleatoria'); ?>">settings</i>
                    </td>
                </tr>
                <tr>
                    <td class="descField"><?php echo _('Clave (repetir)'); ?></td>
                    <td class="valField">
                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                            <input id="password2" name="password2" type="password" required class="mdl-textfield__input fg-blue100" maxlength="255"
                            OnKeyUp="checkPassLevel(this.value)" autocomplete="off">
                            <label class="mdl-textfield__label" for="password2"><?php echo _('Clave (Repetir)'); ?></label>
                        </div>
                        <span class="passLevel fullround"
                              title="<?php echo _('Nivel de fortaleza de la clave'); ?>"></span>
                    </td>
                </tr>
            <?php endif; ?>
            <tr>
                <td class="descField"><?php echo _('Notas'); ?></td>
                <td class="valField">
                <?php if ($showform): ?>
                    <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                        <textarea class="mdl-textfield__input fg-blue100" rows= "3" id="notes" name="notes" maxlength="1000"><?php echo ($gotData) ? $accountData->account_notes : ''; ?></textarea>
                        <label class="mdl-textfield__label" for="notes"><?php echo _('Notas sobre la cuenta'); ?></label>
                    </div>
                <?php else: ?>
                    <?php echo $accountData->account_notes; ?>
                <?php endif; ?>

            </tr>
            <?php if ($showform): ?>
                <tr>
                    <td class="descField"><?php echo _('Permisos'); ?></td>
                    <td class="valField">
                        <div class="account-permissions">
                            <fieldset class="round5">
                                <legend><?php echo _('Usuarios'); ?></legend>
                                <select id="selUsers" name="otherusers[]" multiple="multiple">
                                    <?php
                                    $users = array_flip($otherUsers);

                                    foreach ($users as $otherUserName => $otherUserId) {
                                        $userSelected = '';

                                        if ($gotData && $otherUserId != $accountData->account_userId) {
                                            if (is_array($accountOtherUsers)) {
                                                $userSelected = (in_array($otherUserId, $accountOtherUsers)) ? "selected" : "";
                                            }
                                            echo "<option value='" . $otherUserId . "' $userSelected>" . $otherUserName . "</option>";
                                        } else {
                                            if ($userId === $otherUserId) {
                                                continue;
                                            }
                                            echo "<option value='" . $otherUserId . "' $userSelected>" . $otherUserName . "</option>";
                                        }
                                    }
                                    ?>
                                </select>
                                <br><br>
                                <span><?php echo _('Hablitar edición'); ?></span>

                                <label class="mdl-switch mdl-js-switch mdl-js-ripple-effect" for="ueditenabled">
                                  <input type="checkbox" id="ueditenabled" class="mdl-switch__input" <?php echo $chkUserEdit; ?>/>
                                  <span class="mdl-switch__label"></span>
                                </label>

                            </fieldset>
                        </div>
                        <div class="account-permissions">
                            <fieldset class="round5">
                                <legend><?php echo _('Grupos'); ?></legend>
                                <select id="selGroups" name="othergroups[]" multiple="multiple">
                                    <?php
                                    $groups = array_flip($otherGroups);

                                    foreach ($groups as $otherGroupName => $otherGroupId) {
                                        $uGroupSelected = '';

                                        if ($gotData && $otherGroupId != $accountData->account_userGroupId) {
                                            if (is_array($accountOtherGroups)) {
                                                $uGroupSelected = (in_array($otherGroupId, $accountOtherGroups)) ? "selected" : "";
                                            }
                                            echo "<option value='" . $otherGroupId . "' $uGroupSelected>" . $otherGroupName . "</option>";
                                        } else {
                                            if ($userGroupId === $otherGroupId) {
                                                continue;
                                            }
                                            echo "<option value='" . $otherGroupId . "' $uGroupSelected>" . $otherGroupName . "</option>";
                                        }
                                    }
                                    ?>
                                </select>
                                <br><br>
                                <span><?php echo _('Hablitar edición'); ?></span>

                                <label class="mdl-switch mdl-js-switch mdl-js-ripple-effect" for="geditenabled">
                                  <input type="checkbox" id="geditenabled" class="mdl-switch__input" <?php echo $chkGroupEdit; ?>/>
                                  <span class="mdl-switch__label"></span>
                                </label

                            </fieldset>
                        </div>
                    </td>
                </tr>
            <?php endif; ?>

<?php if ($showform): ?>
    <input type="hidden" name="hash" value="<?php echo $changesHash; ?>">
    <input type="hidden" name="next" value="<?php echo $nextaction; ?>">
    <input type="hidden" name="actionId" value="<?php echo $actionId; ?>">
    <?php if ($gotData): ?>
        <input type="hidden" name="accountid" value="<?php echo $accountId; ?>"/>
    <?php endif; ?>
    <input type="hidden" name="sk" value="<?php echo $sk; ?>">
    <input type="hidden" name="isAjax" value="1">
</form>
<?php endif; ?>

<!--Files boxes-->
<?php if ($showFiles): ?>
    <tr>
        <td class="descField"><?php echo _('Archivos'); ?></td>
        <td class="valField">
            <div id="downFiles"></div>
            <?php if ($accountIsHistory): ?>
                <script>getFiles(<?php echo $accountParentId; ?>, <?php echo intval($showDelete); ?>, '<?php echo $sk; ?>');</script>
            <?php else: ?>
                <script>getFiles(<?php echo $accountId; ?>, <?php echo intval($showDelete); ?>, '<?php echo $sk; ?>');    </script>
                <?php if ($actionId == \SP\Controller\ActionsInterface::ACTION_ACC_EDIT): ?>
                    <form method="post" enctypr="multipart/form-data" name="upload_form" id="fileUpload">
                        <input type="file" id="inFile" name="inFile"/>
                    </form>
                    <div id="dropzone" class="round"
                         data-files-ext="<?php echo $filesAllowedExts; ?>"
                         title="<?php echo _('Soltar archivos aquí (max. 5) o click para seleccionar') . '<br><br>' . _('Tamaño máximo de archivo') . ' ' . $maxFileSize . ' MB'; ?>">
                        <img src="imgs/upload.png" alt="upload" class="opacity50"/>
                    </div>
                    <script> dropFile(<?php echo $accountId; ?>, '<?php echo $sk; ?>', <?php echo $maxFileSize; ?>); </script>
                <?php endif; ?>
            <?php endif; ?>
        </td>
    </tr>
<?php endif; ?>

<?php if ($showHistory && is_array($historyData) && count($historyData) > 0): ?>
    <tr>
        <td class="descField"><?php echo _('Historial'); ?></td>
        <td class="valField">
            <select id="selHistory" name="historyId" class="select-box">
                <option value="0"></option>
                <?php foreach ($historyData as $id => $name): ?>
                    <option
                        value="<?php echo $id; ?>" <?php echo ($gotData && $id === $accountId) ? 'selected' : ''; ?>><?php echo $name; ?></option>
                <?php endforeach; ?>
            </select>
            <script>
                $('#selHistory').on('change', function (e) {
                    var historyId = $('#selHistory').val();

                    if (historyId > 0)
                        doAction(<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_VIEW_HISTORY; ?>,<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_VIEW; ?>, historyId);
                });

                $('#selHistory').chosen({
                    disable_search: true,
                    placeholder_text_single: "<?php echo _('Seleccionar fecha'); ?>"
                });
            </script>
        </td>
    </tr>
<?php endif; ?>

<?php if ($actionId == \SP\Controller\ActionsInterface::ACTION_ACC_EDIT): ?>
    <tr>
        <td class="descField"><?php echo _('Última Modificación'); ?></td>
        <?php if ($accountData->user_editName): ?>
            <td class="valField"><?php echo $accountData->account_dateEdit; ?> <?php echo _('por'); ?> <?php echo $accountData->user_editName; ?></td>
        <?php endif; ?>
    </tr>
<?php endif; ?>
</table>

<!--More info about account details-->
<?php if ($showDetails): ?>
    <table class="data round extra-info">
        <tr>
            <td class="descField"><?php echo _('Visitas'); ?></td>
            <td class="valField"><?php echo $accountData->account_countView . "(" . $accountData->account_countDecrypt . ")"; ?></td>
        </tr>
        <tr>
            <td class="descField"><?php echo _('Fecha Alta'); ?></td>
            <td class="valField"><?php echo $accountData->account_dateAdd ?></td>
        </tr>
        <tr>
            <td class="descField"><?php echo _('Creador'); ?></td>
            <td class="valField"><?php echo ($accountData->user_name) ? $accountData->user_name : $accountData->user_login; ?></td>
        </tr>
        <tr>
            <td class="descField"><?php echo _('Grupo Principal'); ?></td>
            <td class="valField"><?php echo $accountData->usergroup_name; ?></td>
        </tr>
        <?php if (is_array($accountOtherUsers) && count($accountOtherUsers) > 0): ?>
            <tr>
                <td class="descField"><?php echo _('Usuarios Secundarios'); ?></td>
                <td class="valField">
                    <?php
                    foreach ($accountOtherUsersName as $userId => $userName) {
                        if ($userId != $accountData->account_userId) {
                            if (in_array($userId, $accountOtherUsers)) {
                                $accUsers[] = $userName;
                            }
                        }
                    }

                    $usersEdit = ($accountData->account_otherUserEdit) ? '(+)' : '';
                    echo $usersEdit . ' ' . implode(" | ", $accUsers);
                    ?>
                </td>
            </tr>
        <?php endif; ?>
        <?php if (is_array($accountOtherGroups) && count($accountOtherGroups) > 0): ?>
            <tr>
                <td class="descField"><?php echo _('Grupos Secundarios'); ?></td>
                <td class="valField">
                    <?php
                    foreach ($accountOtherGroupsName as $groupId => $groupName) {
                        if ($groupId != $accountData->account_userGroupId) {
                            if (in_array($groupId, $accountOtherGroups)) {
                                $accGroups[] = $groupName;
                            }
                        }
                    }

                    $groupsEdit = ($accountData->account_otherGroupEdit) ? '(+)' : '';

                    echo $groupsEdit . ' ' . implode(" | ", $accGroups);
                    ?>
                </td>
            </tr>
        <?php endif; ?>
        <?php if ($isModified): ?>
            <tr>
                <td class="descField"><?php echo _('Fecha Edición'); ?></td>
                <td class="valField"><?php echo $accountData->account_dateEdit; ?></td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('Editor'); ?></td>
                <td class="valField"><?php echo ($accountData->user_editName) ? $accountData->user_editName : $accountData->user_editLogin; ?></td>
            </tr>
        <?php endif; ?>
    </table>
<?php endif; ?>

<?php if ($gotData && $accountIsHistory): ?>
    <form method="post" name="frmaccount" id="frmAccount" onsubmit="saveAccount('frmAccount'); return false;">
        <input type="hidden" name="hash" value="<?php echo $changesHash; ?>">
        <input type="hidden" name="actionId"
               value="<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_EDIT_RESTORE; ?>">
        <input type="hidden" name="accountid" value="<?php echo $accountId; ?>"/>
        <input type="hidden" name="sk" value="<?php echo $sk; ?>">
        <input type="hidden" name="isAjax" value="1">
    </form>
<?php endif; ?>

<div class="action">
        <?php if ($showDelete): ?>
            <button id="btnDelete" type="button" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored bg-red80" OnClick="delAccount(<?php echo $accountId; ?>,<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_DELETE; ?>,'<?php echo $sk; ?>');" title="<?php echo _('Eliminar Cuenta'); ?>">
                <i class="material-icons">delete</i>
            </button>
        <?php endif; ?>

        <?php if ($showViewPass): ?>
            <button id="btnViewPass" type="button" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored" onClick="viewPass(<?php echo $accountId; ?>,1,<?php echo $accountIsHistory; ?>)" title="<?php echo _('Ver Clave'); ?>">
                <i class="material-icons">lock_open</i>
            </button>
            <button id="btnClipPass" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored" onmousedown="viewPass(<?php echo $accountId; ?>, false, <?php echo $accountIsHistory; ?>)" title="<?php echo _('Copiar Clave en Portapapeles'); ?>">
                <i class="material-icons clip-pass-button"
                   data-clipboard-target="clip-pass-text">content_paste</i>
           </button>
        <?php endif; ?>

        <?php if ($showEditPass): ?>
            <button id="btnEditPass" type="button" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored bg-orange80" OnClick="doAction(<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_EDIT_PASS; ?>,<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_SEARCH; ?>,<?php echo $accountId; ?>)" title="<?php echo _('Modificar Clave de Cuenta'); ?>">
                <i class="material-icons">lock_outline</i>
            </button>
        <?php endif; ?>

        <?php if ($gotData && $accountIsHistory): ?>
            <button id="btnBack" type="button" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored" OnClick="doAction(<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_VIEW; ?>,<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_SEARCH; ?>,<?php echo $accountParentId; ?>)"  title="<?php echo _('Ver Actual'); ?>">
                <i class="material-icons">arrow_back</i>
            </button>
        <?php else: ?>
            <button id="btnBack" type="button" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored" OnClick="doAction(<?php echo $lastAction; ?>, <?php echo $actionId; ?>,<?php echo $accountParentId; ?>)"  title="<?php echo _('Atrás'); ?>">
                <i class="material-icons">arrow_back</i>
            </button>
        <?php endif; ?>

        <?php if ($showEdit): ?>
            <button id="btnEdit" type="button" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored bg-orange80" OnClick="doAction(<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_EDIT; ?>,<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_SEARCH; ?>,<?php echo $accountId; ?>)" title="<?php echo _('Modificar Cuenta'); ?>">
                <i class="material-icons">mode_edit</i>
            </button>
        <?php elseif (!$showEdit && $actionId == \SP\Controller\ActionsInterface::ACTION_ACC_VIEW && \SP\Util::mailrequestIsEnabled()): ?>
            <button id="btnRequest" type="button" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored" OnClick="doAction(<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_REQUEST; ?>,<?php echo \SP\Controller\ActionsInterface::ACTION_ACC_VIEW; ?>,<?php echo $accountId; ?>)" title="<?php echo _('Solicitar Modificación'); ?>">
                <i class="material-icons">email</i>
            </button>
        <?php endif; ?>

        <?php if ($showRestore): ?>
            <button id="btnRestore" name="btnRestore" type="submit" form="frmAccount" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored bg-green80" title="<?php echo _('Restaurar cuenta desde este punto'); ?>">
                <i class="material-icons">restore</i>
            </button>
        <?php endif; ?>

        <?php if ($showSave): ?>
            <button id="btnSave" name="btnRestore" type="submit" form="frmAccount" class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored bg-green80" title="<?php echo _('Guardar'); ?>">
                <i class="material-icons">save</i>
            </button>
        <?php endif; ?>
</div>

<?php if ($showform): ?>
    <script>
        $(function(){
            $("#selCustomer").chosen({
                placeholder_text_single: "<?php echo _('Seleccionar Cliente'); ?>",
                disable_search_threshold: 10,
                no_results_text: "<?php echo _('Sin resultados'); ?>"
            });
            $("#selCategory").chosen({
                placeholder_text_single: "<?php echo _('Seleccionar Categoría'); ?>",
                disable_search_threshold: 10,
                no_results_text: "<?php echo _('Sin resultados'); ?>"
            });
            $("#selGroups").chosen({
                placeholder_text_multiple: "<?php echo _('Seleccionar grupos secundarios'); ?>"
            });
            $("#selUsers").chosen({
                placeholder_text_multiple: "<?php echo _('Seleccionar usuarios'); ?>"
            });
            $('input:text:visible:first').focus();
        });
    </script>
<?php endif; ?>

<?php if ($showViewPass): ?>
    <div id="clip-pass-text" style="visibility: hidden"></div>

    <script>
        passToClip = 0;

        $(function(){
            function clipboard() {
                var client = new ZeroClipboard($('.clip-pass-button'), {
                    swfPath: "js/ZeroClipboard.swf",
                    debug: false,
                    title: '<?php echo _('Copiar Clave en Portapapeles'); ?>'
                });

                client.on("aftercopy", function (e) {
                    resMsg("ok", "<?php echo _('Clave Copiada al Portapapeles'); ?>");
                });

                client.on("error", function (e) {
                    ZeroClipboard.destroy();
                });
            }

            clipboard();
        });
    </script>
<?php endif; ?>