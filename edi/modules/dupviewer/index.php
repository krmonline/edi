<?php 
require('../../Group-Office.php');
$GO_SECURITY->authenticate();
$GO_MODULES->authenticate('dupviewer');
require($GO_THEME->theme_path.'header.inc');
?>
<script language="javascript">
Ext.onReady(function(){
	var duplicate_store = new Ext.data.JsonStore({
	    autoDestroy: true,
	    url: 'json.php',
	    baseParams:{
			action:'getlog'
		},
		remoteSort : true,
	    storeId: 'duplicate_store',
	    autoLoad:true,
	    root: 'docs',
	    idProperty: 'id',
	    fields: ['id','date', 'sender','recipient','subject','duplicate','action','filename']
	});

	PagingSearch = Ext.extend(Ext.PagingToolbar,{
        store: duplicate_store,
        prependButtons: true,
        displayInfo: true,
        autoDestroy: true,
        refreshText: 'Refresh',
        disabled: false,
        hidden: false,
        stateful: false,
        initComponent: function() {
    		PagingSearch.superclass.initComponent.call(this);
    	}
    });
    PagingSearch = new PagingSearch;

    
	var panel = new Ext.Panel({
		xtype:'panel',
		//width:'800',
		height:'300',
		renderTo : 'main_panel',
		autoHeight: true,
		items:[{
			xtype:'grid',
			store: duplicate_store,
			remoteSort:true,
			sortable: true,
			autoHeight: true,
			title:'Duplicate Log',
			tbar:[PagingSearch,{
				xtype:'button',
				text:'Clear DATA',
				handler : function(b,e){
					//Ext.Msg.alert("test");
					Ext.Ajax.request({
					    url: 'json.php',
					    params: { action: 'cleardata'},
					    success: function (response, opts){
					         response = Ext.decode(response.responseText);
					         b = response;
					        if(response.status == "ok"){
					            Ext.Msg.alert("Alert","Clear data success.");
					        }
					        //mycmp.setValue(b.format);
					     },
					});
				}
			}],
			columns:[
				{header:'Date',dataIndex:'date',width:150,sortable: true},
				{header:'Sender',dataIndex:'sender',width:200,sortable: true},
				{header:'To',dataIndex:'recipient',width:200,sortable: true},
				{header:'Subject',dataIndex:'subject',width:200,sortable: true},
				{header:'Duplicate',dataIndex:'duplicate',width:100,sortable: true},
				{header:'Action',dataIndex:'action',width:100,sortable: true},
				{header:'Filename',dataIndex:'filename',width:400,sortable: true}
			]
		}]
	});
});
</script>
<div id="main_panel"></div>
<?php
require($GO_THEME->theme_path.'footer.inc');
?>
