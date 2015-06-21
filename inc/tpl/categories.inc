<div id="fancyContainer" align="center">
    <h2 class="midround"><?php echo $header; ?></H2>

    <form method="post" name="frmCategories" id="frmCategories">
        <table class="fancydata">
            <tbody>
            <tr>
                <td class="descField"><?php echo _('Nombre'); ?></td>
                <td class="valField">
                    <input type="text" id="grpname" name="name" title="<?php echo _('Nombre de la categoría'); ?>"
                           value="<?php echo $category["category_name"] ?>"/>
                </td>
            </tr>

            <tr>
                <td class="descField"><?php echo _('Descripción'); ?></td>
                <td class="valField"><input type="text" id="grpdesc" name="description"
                                            title="<?php echo _('Descripción de la categoría'); ?>"
                                            value="<?php echo $category["category_description"]; ?>"/>
                </td>
            </tr>
            </tbody>
        </table>

        <input type="hidden" name="activeTab" value="<?php echo $activeTab ?>"/>
        <input type="hidden" name="onCloseAction" value="<?php echo $onCloseAction ?>"/>
        <input type="hidden" name="itemId" value="<?php echo $category["category_id"]; ?>"/>
        <input type="hidden" name="actionId" value="<?php echo $actionId; ?>"/>
        <input type="hidden" name="sk" value="<?php echo $sk; ?>">
        <input type="hidden" name="isAjax" value="1">
    </form>
    <div id="resCheck"><span id="resFancyAccion"></span></div>
    <div class="action-in-box">
        <ul>
            <li><img src="imgs/check.png" title="<?php echo _('Guardar'); ?>" class="inputImg"
                     OnClick="appMgmtSave('frmCategories');"/></li>
        </ul>
    </div>
</div>