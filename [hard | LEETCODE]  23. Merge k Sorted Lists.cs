/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public UInt32 getSizeOfListNodes(ListNode pHeadListNode)
    {
        UInt32 size = 0;
        ListNode head = pHeadListNode;

        while(head != null)
        {
            size++;
            head = head.next;
        }

        return size;
    }
        public bool isEmpty(List<ListNode> pLists)
        {
            foreach (var item in pLists)
            {
                if (item != null)
                    return false;
            }
            return true;
        }
                public List<Int32> getSortedListNumbersOfNodes(List<ListNode> pListNodes)
        {
        List<Int32> sortedListNodes = new List<Int32>();

        foreach (var item in pListNodes)
        {
            UInt32 sizeOfCurrentNode = getSizeOfListNodes(item);
            ListNode tempListNode = item;
            for(UInt32 i = 0; i < sizeOfCurrentNode; ++i)
            {
                sortedListNodes.Add(tempListNode.val);
                tempListNode = tempListNode.next;
            }
        }
            return sortedListNodes;
        }
        
    public ListNode MergeKLists(ListNode[] pLists)
    {
        List<ListNode> listNodes = new List<ListNode>(pLists);

            if (listNodes.Count() == 0 || isEmpty(listNodes))
                return null;
            

            List<Int32> sortedListNodes = getSortedListNumbersOfNodes(listNodes);

        sortedListNodes.Sort();
        ListNode resultListNode = new ListNode(sortedListNodes[0]);
        ListNode pointerListNode = resultListNode;

        for(Int32 i = 1; i < sortedListNodes.Count(); ++i)
        { 
            pointerListNode.next = new ListNode(sortedListNodes[i]);
            pointerListNode = pointerListNode.next;
        }

        return resultListNode;
    }
}
